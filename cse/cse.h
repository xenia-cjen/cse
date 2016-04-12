/*
 * =====================================================================================
 *
 *       Filename:  cse.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年04月09日 16時13分44秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  xenia-cjen (xc), jonah0604@gmail.com
 *        Company:  LaDS(I), GIEE, NTU
 *
 * =====================================================================================
 */

#ifndef _MY_CSE_H_ 
#define _MY_CSE_H_

#include <tuple>
#include <map>

#include <llvm/Pass.h> 
#include <llvm/IR/Function.h> 
#include <llvm/Support/raw_ostream.h> 

using namespace llvm; 

typedef std::tuple<unsigned, Value *, Value *> BinInstKey; 
typedef std::map<BinInstKey, Value *> BinInstMap;  
typedef std::map<Value *, Value *> LoadInstMap; 
// typedef std::map<>

class MyCSE : public FunctionPass {
public: 
    static char ID; 
    MyCSE() : FunctionPass(ID) {} 
    ~MyCSE(); 
    bool runOnFunction(Function &F) override; 

protected: 
    static unsigned CSERedund; 
    static unsigned CSEInst; 
}; 

#endif //_MY_CSE_H_
