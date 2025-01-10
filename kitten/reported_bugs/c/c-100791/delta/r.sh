#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: verify_gimple failed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "verify_gimple_in_cfg(function*, bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_function_todo" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_todo" "${OUTPUT}" ; then
  exit 1
fi
exit 0