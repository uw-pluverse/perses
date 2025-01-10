#!/usr/bin/env bash
set -o nounset
set -o pipefail
set -o xtrace

readonly OUTPUT="temp_compilation_output.tmp.txt"
readonly CRASH_EXIT_CODE=4

timeout -s 9 30 slang-trunk  mutant.v &> "${OUTPUT}"

[[ "$?" == "${CRASH_EXIT_CODE}" ]] || exit 1

if ! grep --quiet --fixed-strings "internal compiler error: Assertion 'init->constant' failed" "${OUTPUT}" ; then
  exit 1
fi
exit 0