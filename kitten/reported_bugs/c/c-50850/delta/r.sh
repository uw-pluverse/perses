#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "void llvm::CallInst::init(llvm::FunctionType*, llvm::Value*, llvm::ArrayRef<llvm::Value*>, llvm::ArrayRef<llvm::OperandBundleDefT<llvm::Value*> >, const llvm::Twine&): Assertion \`(i >= FTy->getNumParams() || FTy->getParamType(i) == Args[i]->getType()) && \"Calling a function with a bad signature!\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0