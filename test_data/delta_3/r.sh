#!/usr/bin/env bash

rm a.out temp.txt &> /dev/null

# Check the program does not have cerntain errors.
if ! gcc -Wall -Wextra t.c &> temp.txt ; then
  exit 1
fi

if ! clang -Weverything t.c >> temp.txt 2>&1 ; then
  exit 1
fi

if grep -q "Wimplicit-int" temp.txt || \
   grep -q "defaulting to type" temp.txt || \
   grep -q "too few arguments" temp.txt ; then
  exit 1
fi
# End of the check.

if ! clang -fsanitize=address,undefined -fno-sanitize-recover=undefined,address t.c &> /dev/null ; then
  exit 1
fi

./a.out

if [[ "$?" != 99 ]] ; then
  exit 1
fi

./a.out

if [[ "$?" != 99 ]] ; then
  exit 1
fi

exit 0
