#!/usr/bin/env bash

set -o nounset

gcc -o tmp test_data_type_elimination.c

output=$(./tmp)

if [[ "$output" == "2" ]]; then
  exit 0
else
  exit 1
fi
