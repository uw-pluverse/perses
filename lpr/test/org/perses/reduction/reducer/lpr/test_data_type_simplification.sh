#!/usr/bin/env bash

set -o nounset

gcc -o tmp test_data_type_simplification.c

output=$(./tmp)

if [[ "$output" == "1" ]]; then
  exit 0
else
  exit 1
fi
