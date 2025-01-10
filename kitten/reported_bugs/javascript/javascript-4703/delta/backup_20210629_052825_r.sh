#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 jerry-trunk-asan_ubsan  mutant.js &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "/tmp/tmp.F2MvT4tsOz/jerryscript/jerry-core/vm/vm.c:3731:77:  left shift of 33554431 by 22 places cannot be represented in type 'int'" "${OUTPUT}" ; then
  exit 1
fi
exit 0