#!/usr/bin/env bash

rm a.out temp.txt &> /dev/null

if ! gcc -Wall t.c &> temp.txt ; then
  exit 1
fi

if ! ccomp -interp -fall t.c ; then 
  exit 1
fi

if grep -q "Wimplicit-int" temp.txt ; then
  exit 1
fi

./a.out > temp.txt

if grep -q 'hello' temp.txt ; then
  exit 0
fi

exit 1
