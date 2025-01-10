#!/usr/bin/env bash
set -o nounset
set -o pipefail
set -o xtrace

readonly OUTPUT="temp_compilation_output.tmp.txt"
readonly CRASH_EXIT_CODE=101

timeout -s 9 30 slang-trunk  mutant.sv &> "${OUTPUT}"

[[ "$?" == "${CRASH_EXIT_CODE}" ]] || exit 1

if ! grep --quiet --fixed-strings "internal compiler error: Assertion '!arg.isError()' failed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Type.cpp" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "function: slang::Diagnostic &slang::operator<<(slang::Diagnostic &, const slang::Type &)" "${OUTPUT}" ; then
  exit 1
fi
exit 0