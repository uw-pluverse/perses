#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in assign_stack_temp_for_type, at function.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assign_stack_temp_for_type(machine_mode, poly_int<1u, long>, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assign_temp(tree_node*, int, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_call(tree_node*, rtx_def*, int)" "${OUTPUT}" ; then
  exit 1
fi
exit 0