#!/usr/bin/env bash

set -o nounset

rm a.out temp.txt &> /dev/null

readonly GCC=g++
readonly CLANG=clang++
readonly SRC="t.cpp"

# Check the program does not have cerntain errors.
if ! "${GCC}" -std=c++11 -Wall -Wextra "${SRC}" &> temp.txt ; then
  exit 1
fi

if ! "${CLANG}" -std=c++11 -Weverything "${SRC}" >> temp.txt 2>&1 ; then
  exit 1
fi

if
#   grep -q "Wimplicit-int" temp.txt || \
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
