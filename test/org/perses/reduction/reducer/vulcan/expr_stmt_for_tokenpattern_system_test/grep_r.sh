#!/usr/bin/env bash

set -o nounset

# A fast, compiler-free interestingness test: the program stays interesting as long as it still
# mentions "var".
grep "var" t.c
