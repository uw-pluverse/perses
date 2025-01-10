#!/usr/bin/env bash

set -o nounset

regex='int[[:space:]]+main[[:space:]]*\([[:space:]]*\)[[:space:]]*\{'+\
'[[:space:]]*[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*\([[:space:]]*\)[[:space:]]*;'+\
'[[:space:]]*return[[:space:]]+0x[1-9a-fA-F][0-9a-fA-F]{2,}ull[[:space:]]*;'+\
'[[:space:]]*\}[[:space:]]*'

content=$(<"t.c")

if [[ $content =~ $regex ]]; then
  exit 0
else
  exit 1
fi
