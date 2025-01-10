#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in get_constant, at c-family/c-format.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "get_constant" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "decode_format_attr" "${OUTPUT}" ; then
  exit 1
fi
exit 0