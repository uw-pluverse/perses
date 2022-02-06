#!/usr/bin/env bash

set -o nounset
set -o pipefail

rm a.out temp.txt &> /dev/null

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

# Since we do not use CompCert, it is unavoidable to have UBs. Thus we rely on multiple optimization flags.
readonly COMPILE_CMD_LIST=(
    "-O0"
    "-O1"
    "-O2"
    "-O3"
    "-Os"
)

for compiler in "${GCC}" "${CLANG}" ; do
  for flag in "${COMPILE_CMD_LIST[@]}" ; do
    echo ${flag}
    "${compiler}" "${flag}" t.c || exit 1
    ./a.out | grep "b=2" || exit 1
  done
done

exit 0
