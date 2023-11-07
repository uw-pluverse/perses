#!/usr/bin/env bash

set -o nounset

readonly BIN="temp_a.out"
rm "${BIN}" temp.txt &> /dev/null
trap "rm ${BIN} temp.txt" EXIT
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
if ! "${GCC}" -Wall -Wextra t.c -o "${BIN}" &> temp.txt ; then
  exit 1
fi

if ! "${CLANG}" -Weverything t.c -o "${BIN}" >> temp.txt 2>&1 ; then
  exit 1
fi

if grep -q "Wimplicit-int" temp.txt || \
   grep -q "defaulting to type" temp.txt || \
   grep -q "Wmain-return-type" temp.txt || \
   grep -q "Wimplicit-function-declaration" temp.txt || \
   grep -q "Wincompatible-library-redeclaration" temp.txt || \
   grep -q "Wformat" temp.txt || \
   grep -q "too few arguments" temp.txt ; then
  exit 1
fi
# End of the check.

timeout -s 9 3 "./${BIN}"

EXIT_CODE="$?"

if [[ ${EXIT_CODE} -lt 2 || ${EXIT_CODE} -eq 137 ]] ; then
  exit 1
fi

exit 0
