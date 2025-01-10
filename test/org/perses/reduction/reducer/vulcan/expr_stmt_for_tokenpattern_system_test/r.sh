#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

readonly FILE="t.c"
readonly OUTPUT="temp.txt"
readonly VALGRIND_OUTPUT="valgrind_temp.txt"
readonly EXE="./temp.out"

# Make sure both gcc and clang can capture all possible warnings.
gcc -Wall -Wextra "${FILE}" > "${OUTPUT}" 2>&1 || exit 1
clang -Wall -Wextra "${FILE}" -o "${EXE}" >> "${OUTPUT}" 2>&1 || exit 1


valgrind "${EXE}" > "${VALGRIND_OUTPUT}" 2>&1
if [[ "$?" != 99 ]] ; then
  exit 1
fi
if grep -q "Wimplicit-int" temp.txt || \
   grep -q "defaulting to type" temp.txt || \
   grep -q "return type defaults to" temp.txt || \
   grep -q "uninitialized" temp.txt || \
   grep -q "too few arguments" temp.txt ; then
  exit 1
fi

readonly OCCURRENCE=3
if [[ "$(grep -c "var" "${FILE}")" != "${OCCURRENCE}" ]] ; then
  exit 1
fi

if [[ "$(grep -c ";" "${FILE}")" != "${OCCURRENCE}" ]] ; then
  exit 1
fi

if grep "^ *fun.*var" "${FILE}" || grep '^ *var *;$' "${FILE}" ; then
  exit 0
else
  exit 1
fi
