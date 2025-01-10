#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "void {anonymous}::LValue::setFrom(clang::ASTContext&, const clang::APValue&): Assertion \`V.isLValue() && \"Setting LValue from a non-LValue?\"' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE submit a bug report to" "${OUTPUT}" ; then
  exit 1
fi
exit 0