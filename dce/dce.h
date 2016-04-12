/*
 * =====================================================================================
 *
 *       Filename:  dce.h
 *
 *    Description:  Header File: Dead Code Elimination 
 *
 *        Version:  1.0
 *        Created:  2016年03月08日 21時10分51秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  xenia-cjen (xc), jonah0604@gmail.com
 *        Company:  LaDS(I), GIEE, NTU
 *
 * =====================================================================================
 */

#ifndef _MY_DCE_H_ 
#define _MY_DCE_H_

//#define SMALL_VEC_SIZE  = 256 

#include <llvm/ADT/SetVector.h>
#include <llvm/Pass.h>
#include <llvm/IR/Function.h> 
#include <llvm/Analysis/TargetLibraryInfo.h>
#include <llvm/Support/raw_ostream.h> 

using namespace llvm; 

//typedef SmallSetVector<Instruction *, SMALL_VEC_SIZE> InstSet; 
typedef SmallSetVector<Instruction *, 256> InstSet; 

class MyDCE : public FunctionPass {
public: 
    static char ID;  
    MyDCE() : FunctionPass(ID) {} 
    ~MyDCE(); 
    bool runOnFunction(Function &F) override; 

protected: 
    bool MyDCEInstruction(Instruction *inst, 
                          InstSet &work_list, 
                          const TargetLibraryInfo *tli); 
    static size_t DCEEliminated; 
    static size_t DCEInst; 
                          
}; 

#endif // _MY_DCE_H_
