#!/usr/bin/env bash
set -o nounset
set -o pipefail
set -o xtrace

readonly OUTPUT="temp_compilation_output.tmp.txt"
readonly CRASH_EXIT_CODE=101

timeout -s 9 30 slang-trunk  mutant.sv &> "${OUTPUT}"

[[ "$?" == "${CRASH_EXIT_CODE}" ]] || exit 1

if ! grep --quiet --fixed-strings "internal compiler error: /tmp/tmp.8mv1csjR86/slang-nightly/source/binding/Statements.cpp:1032: Default case should be unreachable!" "${OUTPUT}" ; then
  exit 1
fi
exit 0