#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "clang::QualType clang::Sema::GetSignedVectorType(clang::QualType): Assertion \`TypeSize == Context.getTypeSize(Context.CharTy) && \"Unhandled vector element size in vector compare\"' failed." "${OUTPUT}" ; then
  exit 1
fi
exit 0