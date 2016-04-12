#!/bin/sh 

cd test/ 

clang-3.7 -emit-llvm -S test_simple.c -o test_simple.ll 
opt-3.7 -load ../build/cse/libMyCSE.so -MyCSE -S test_simple.ll -o test_simple.cse 
opt-3.7 -load ../build/dce/libMyDCE.so -MyDCE -S test_simple.cse -o test_simple.dce 
clang-3.7 test_simple.ll -o test_simple

cd .. 
