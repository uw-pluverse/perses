#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 clang-trunk -O3 -g3 -c -Wall -Wextra -Weverything mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "const T* clang::Type::castAs() const [with T = clang::PointerType]: Assertion \`isa<T>(CanonicalType)' failed." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "PLEASE submit a bug report to" "${OUTPUT}" ; then
  exit 1
fi
exit 0