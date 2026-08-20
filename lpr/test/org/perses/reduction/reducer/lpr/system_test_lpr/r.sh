#!/usr/bin/env bash

set -o nounset

gcc -Wall -Wextra -Werror \
  -Wconversion \
  -pedantic \
  -std=c11 \
  -O2 \
  -o tmp t.c

output=$(timeout -s 9 3s ./tmp)

if [[ "${output}" == "94" ]]; then
  exit 0
else
  exit 1
fi
