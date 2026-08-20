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

# The three files live in subdirectories (src/, lib/) but are reduced together: compile them as one
# program and reject any variant whose warnings reveal a common undefined behavior (implicit int,
# implicit function declaration, etc.). This is the same warning-based guard as
# benchmark_toys/multi_file_three_c/r.sh; without it the reduction result would differ across
# compiler versions. The point of this benchmark is that the input/output files sit in directories.
if ! "${GCC}" -Wall -Wextra src/a.c lib/b.c src/main.c &> temp.txt; then
  exit 1
fi

if ! "${CLANG}" -Weverything src/a.c lib/b.c src/main.c >> temp.txt 2>&1; then
  exit 1
fi

if grep -q "Wimplicit-int" temp.txt \
  || grep -q "defaulting to type" temp.txt \
  || grep -q "Wmain-return-type" temp.txt \
  || grep -q "Wimplicit-function-declaration" temp.txt \
  || grep -q "Wincompatible-library-redeclaration" temp.txt \
  || grep -q "too few arguments" temp.txt; then
  exit 1
fi
# End of the check.

# The program must still print the cross-file sum 49 (= compute_a() + compute_b()).
./a.out > temp.txt

if grep -q 'sum = 49' temp.txt; then
  exit 0
fi

exit 1
