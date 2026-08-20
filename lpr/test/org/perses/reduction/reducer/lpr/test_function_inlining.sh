#!/usr/bin/env bash

set -o nounset

gcc -o tmp test_function_inlining.c

output=$(./tmp)

if [[ "$output" == "2" ]]; then
  exit 0
else
  exit 1
fi
