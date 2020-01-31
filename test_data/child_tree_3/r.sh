#!/usr/bin/env bash

rm a.out temp.txt comp.txt &> /dev/null

if ! gcc -Wall -Wextra t.c &> temp.txt; then
  exit 1
fi

if grep -q "uninitialize" temp.txt ; then
  exit 1
fi

if ! timeout -s 9 1 ./a.out > temp.txt ; then
  exit 1
fi




if grep -q 'world' temp.txt ; then
  exit 0
fi

exit 1
