#!/usr/bin/env bash

set -o nounset

rm a.out temp.txt &> /dev/null
cp t.unique t.c
readonly FILE="t.c"
if command -v gcc-7.1.0 ; then
  GCC="gcc-7.1.0"
else
  GCC="gcc"
fi

if command -v clang-7.1.0 ; then
  CLANG="clang-7.1.0"
else
  CLANG="clang"
fi

# Check the program does not have cerntain errors.
if ! "${GCC}" -Wall -Wextra "${FILE}" &> temp.txt ; then
  exit 1
fi

if ! "${CLANG}" -Weverything "${FILE}" >> temp.txt 2>&1 ; then
  exit 1
fi

if grep -q "Wimplicit-int" temp.txt || \
   grep -q "defaulting to type" temp.txt || \
   grep -q "Wmain-return-type" temp.txt || \
   grep -q "Wimplicit-function-declaration" temp.txt || \
   grep -q "Wincompatible-library-redeclaration" temp.txt || \
   grep -q "too few arguments" temp.txt ; then
  exit 1
fi
# End of the check.

./a.out > temp.txt

if grep -q 'world' temp.txt ; then
  exit 0
fi

exit 1
