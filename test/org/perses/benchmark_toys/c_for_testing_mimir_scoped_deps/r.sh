#!/usr/bin/env bash

set -o nounset

rm a.out temp.txt &> /dev/null

if command -v gcc-7.1.0; then
  GCC="gcc-7.1.0"
else
  GCC="gcc"
fi

if command -v clang-7.1.0; then
  CLANG="clang-7.1.0"
else
  CLANG="clang"
fi

readonly FILES="t.c"
# Check the program does not have cerntain errors.
if ! "${GCC}" -Wall -Wextra ${FILES} &> temp.txt; then
  exit 1
fi

if ! "${CLANG}" -Weverything ${FILES} >> temp.txt 2>&1; then
  exit 1
fi

if grep -q "Wimplicit-int" temp.txt \
  || grep -q "empty declaration" temp.txt \
  || grep -q "Wmissing-declaration" temp.txt \
  || grep -q "Wuninitialized" temp.txt \
  || grep -q "defaulting to type" temp.txt \
  || grep -q "Wmain-return-type" temp.txt \
  || grep -q "Wimplicit-function-declaration" temp.txt \
  || grep -q "Wincompatible-library-redeclaration" temp.txt \
  || grep -q "Wformat" temp.txt \
  || grep -q "too few arguments" temp.txt; then
  exit 1
fi
# End of the check.

rm temp.txt
./a.out > temp.txt

if grep -q '8888' temp.txt; then
  exit 0
fi

exit 1
