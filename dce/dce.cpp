/*
 * =====================================================================================
 *
 *       Filename:  dce.cpp
 *
 *    Description:  class MyDCE implementation 
 *
 *        Version:  1.0
 *        Created:  2016年03月08日 21時21分45秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  xenia-cjen (xc), jonah0604@gmail.com
 *        Company:  LaDS(I), GIEE, NTU
 *
 * =====================================================================================
 */

#include <queue>

#include <llvm/Transforms/Utils/Local.h> // llvm::isInstructionTriviallyDead
#include <llvm/IR/InstIterator.h>

#include "dce.h"

using namespace std; 
using namespace llvm; 

typedef queue<Instruction *> InstQueue;  

size_t MyDCE::DCEInst = 0; 
size_t MyDCE::DCEEliminated = 0; 
char MyDCE::ID = 0; 

static RegisterPass<MyDCE> X("MyDCE", "My DCE Pass", false, false); 

bool MyDCE:: MyDCEInstruction(Instruction *inst, 
                              InstSet &work_list, 
                              const TargetLibraryInfo *tli) {
    if (isInstructionTriviallyDead(inst, tli)) 
        return false; 
    
    for (unsigned i=0; i<inst->getNumOperands(); i++) {
        Value *op = inst->getOperand(i); 
        if (Instruction *opi = dyn_cast<Instruction>(op)) 
            MyDCEInstruction(opi, work_list, tli); 
    }
    
    work_list.remove(inst); 
    return true; 
}

bool MyDCE::runOnFunction(Function &F) {
    if (skipOptnoneFunction(F)) 
        return false;  

    auto *tlip = getAnalysisIfAvailable<TargetLibraryInfoWrapperPass>(); 
    TargetLibraryInfo *tli = tlip?&tlip->getTLI():nullptr; 

    // size_t n_inst = 0; 
    InstSet work_list; 
    for (auto ii=inst_begin(F); ii!=inst_end(F); ++ii) 
        work_list.insert(&*ii); 

    DCEInst+=work_list.size(); 

    bool made_change = false; 
    InstQueue dead_inst_list; 
    while (!work_list.empty()) {
        Instruction *inst = work_list[0]; 
        work_list.remove(inst); 
        
        if (!MyDCEInstruction(inst, work_list, tli))  
           dead_inst_list.push(inst); 
        else 
            made_change = true; 
    }

    DCEEliminated += dead_inst_list.size(); 

    while (!dead_inst_list.empty()) { 
        dead_inst_list.front()->eraseFromParent(); 
        dead_inst_list.pop(); 
    }

    return made_change; 
}

MyDCE::~MyDCE() {
    errs() << "Total number of inst(s) removed: "; 
    errs() << DCEEliminated << " out of "; 
    errs() << DCEInst << ". \n"; 
}
