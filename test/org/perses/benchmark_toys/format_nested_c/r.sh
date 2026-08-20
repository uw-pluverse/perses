#!/usr/bin/env bash

# The single source file lives in a subdirectory (src/t.c), so the reduction folder is nested. This
# exercises FormatReducer running the formatter with the file's *root-relative* path (src/t.c), not
# its bare base name (t.c) -- the latter would not be found with the folder as the working directory.

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

# Check the program does not have certain errors.
if ! "${GCC}" -Wall -Wextra src/t.c &> temp.txt; then
  exit 1
fi

if ! "${CLANG}" -Weverything src/t.c >> temp.txt 2>&1; then
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

./a.out > temp.txt

if grep -q 'world' temp.txt; then
  exit 0
fi

exit 1
