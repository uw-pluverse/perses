#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "typename llvm::cast_retty<X, Y*>::ret_type llvm::cast(Y*) [with X = llvm::ConstantInt; Y = llvm::Value; typename llvm::cast_retty<X, Y*>::ret_type = llvm::ConstantInt*]: Assertion \`isa<X>(Val) && \"cast<Ty>() argument of incompatible type!\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0