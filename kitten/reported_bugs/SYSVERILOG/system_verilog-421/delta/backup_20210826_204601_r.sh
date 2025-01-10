#!/usr/bin/env bash
set -o nounset
set -o pipefail
set -o xtrace

readonly OUTPUT="temp_compilation_output.tmp.txt"
readonly CRASH_EXIT_CODE=101

timeout -s 9 30 slang-trunk  mutant.v &> "${OUTPUT}"

[[ "$?" == "${CRASH_EXIT_CODE}" ]] || exit 1

if ! grep --quiet --fixed-strings "internal compiler error: Assertion 'visitor.errored || seenBindDirectives.size() == numBinds' failed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Compilation.cpp" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "function: const slang::RootSymbol &slang::Compilation::getRoot(bool)" "${OUTPUT}" ; then
  exit 1
fi
exit 0