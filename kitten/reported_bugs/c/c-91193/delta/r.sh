#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: tree check: expected class ‘type’, have ‘declaration’ (function_decl) in grokdeclarator, at c/c-decl.c" "${OUTPUT}" ; then
  exit 1
fi
exit 0