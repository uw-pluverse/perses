#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 jerry-trunk-asan_ubsan  mutant.js &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "/tmp/tmp.F2MvT4tsOz/jerryscript/jerry-core/ecma/base/ecma-helpers-conversion.c:702:5:  shift exponent 64 is too large for 64-bit type 'long unsigned int'" "${OUTPUT}" ; then
  exit 1
fi
exit 0