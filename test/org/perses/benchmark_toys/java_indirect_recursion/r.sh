#!/usr/bin/env bash

set -o nounset
set -o errexit

rm -f Hello.class temp.txt
cp Hello.java.txt Hello.java
timeout -s 9 10 javac Hello.java
timeout -s 9 10 java Hello > temp.txt

if grep -q "hello" temp.txt; then
  exit 0
fi

exit 1
