#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in noninterposable_alias, at symtab.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symtab_node::noninterposable_alias()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "function_and_variable_visibility" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "whole_program_function_and_variable_visibility" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0