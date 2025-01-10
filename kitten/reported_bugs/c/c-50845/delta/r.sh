#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "static llvm::CastInst* llvm::CastInst::Create(llvm::Instruction::CastOps, llvm::Value*, llvm::Type*, const llvm::Twine&, llvm::Instruction*): Assertion \`castIsValid(op, S, Ty) && \"Invalid cast!\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:" "${OUTPUT}" ; then
  exit 1
fi
exit 0