#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 solc-trunk-asan_ubsan --optimize mutant.sol &> "${OUTPUT}" ; then 
  exit 1
fi

if ! grep --quiet --fixed-strings "Internal compiler error during compilation:" "${OUTPUT}" ; then
  exit 1
fi
exit 0