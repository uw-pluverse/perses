#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 jerry-trunk-asan_ubsan  mutant.js &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "/tmp/tmp.FMvTtsOz/jerryscript/jerry-core/ecma/operations/ecma-regexp-object.c::: runtime error: variable length array bound evaluates to non-positive value" "${OUTPUT}" ; then
  exit 1
fi
exit 0