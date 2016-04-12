/*
 * =====================================================================================
 *
 *       Filename:  cse.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年04月09日 16時34分28秒
 *       Revision:  none
 *       Compiler:  g++ 
 *
 *         Author:  xenia-cjen (xc), jonah0604@gmail.com
 *        Company:  LaDS(I), GIEE, NTU
 *
 * =====================================================================================
 */

#include <llvm/IR/Instruction.h>

#include "cse.h" 

using namespace llvm; 
using namespace std; 

unsigned MyCSE::CSEInst = 0; 
unsigned MyCSE::CSERedund = 0; 
char MyCSE::ID = 0; 

static RegisterPass<MyCSE> X("MyCSE", "My CSE Pass", false, false); 

bool MyCSE::runOnFunction(Function &F) {
    bool modified = false; 

    BinInstMap bimap; 
    LoadInstMap limap; 

    for (auto b=F.begin(); b!=F.end(); ++b) { 
        BasicBlock &bb = *b; 
        for (auto i=bb.begin(); i!=bb.end(); ++i) {
            CSEInst++; 
        }
        for (auto i=bb.begin(); i!=bb.end(); ++i) {
            Instruction &inst = *i; 
            if (inst.isBinaryOp()) {
                auto ret = bimap.insert(make_pair(
                    make_tuple(inst.getOpcode(), 
                        inst.getOperand(0), 
                        inst.getOperand(1)), 
                    &inst)); 

                if (!ret.second) { 
                    modified = true; 
                    CSERedund++; 
                    for (auto ui=inst.user_begin(); ui!=inst.user_end(); ++ui) { 
                        ui->replaceUsesOfWith(&inst, ret.first->second); 
                    }
                } 
            } 
            else if (inst.getOpcode()==Instruction::Load) {
                auto ret = limap.insert(make_pair(
                    inst.getOperand(0), 
                    &inst)); 

                if (!ret.second) { 
                    modified = true; 
                    CSERedund++; 
                    for (auto ui=inst.user_begin(); ui!=inst.user_end(); ++ui) { 
                        ui->replaceUsesOfWith(&inst, ret.first->second); 
                    }
                } 
            }
            else if (inst.getOpcode()==Instruction::Store) {
                auto ret = limap.find(inst.getOperand(1)); 
                if (ret!=limap.end()) limap.erase(ret); 
            }
        }
    }

    return modified; 
}

MyCSE::~MyCSE() {
    errs() << "Total number of redund. inst(s) found: "; 
    errs() << CSERedund << " out of "; 
    errs() << CSEInst << ". \n"; 
}
