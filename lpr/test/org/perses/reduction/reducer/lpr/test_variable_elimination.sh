#!/usr/bin/env bash

set -o nounset

gcc -o tmp test_variable_elimination.c
output=$(timeout -s 9 10s ./tmp)

if [[ "${output}" == "1" ]]; then
  exit 0
else
  exit 1
fi
