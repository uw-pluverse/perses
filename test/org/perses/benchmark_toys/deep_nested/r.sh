#!/usr/bin/env bash


set -o nounset
set -o pipefail

rm a.out temp.txt &> /dev/null

readonly GCC="gcc"
readonly CLANG="clang"

# Check the program does not have cerntain errors.
if ! "${GCC}" -Wall -Wextra t.c &> temp.txt ; then
  exit 1
fi

if ! "${CLANG}" -Weverything t.c >> temp.txt 2>&1 ; then
  exit 1
fi

if grep -q "Wimplicit-int" temp.txt || \
   grep -q "defaulting to type" temp.txt || \
   grep -q "uninitialized" temp.txt || \
   grep -q "Wimplicit-function-declaration" temp.txt || \
   grep -q "Wformat" temp.txt || \
   grep -q "too few arguments" temp.txt ; then
  exit 1
fi
# End of the check.

./a.out
readonly EXIT_CODE="$?"

if [[ "${EXIT_CODE}" == "99" ]] ; then
  exit 0
fi

exit 1
