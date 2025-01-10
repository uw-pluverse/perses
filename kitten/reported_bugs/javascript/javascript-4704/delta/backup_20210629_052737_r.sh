#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 jerry-trunk-asan_ubsan  mutant.js &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "/tmp/tmp.F2MvT4tsOz/jerryscript/jerry-core/ecma/builtin-objects/ecma-builtin-helpers-date.c:82:27:  signed integer overflow: 19998030 * 365 cannot be represented in type 'int'" "${OUTPUT}" ; then
  exit 1
fi
exit 0