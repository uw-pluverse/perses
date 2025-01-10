#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: Segmentation fault" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "crash_signal" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "contains_struct_check(tree_node*, tree_node_structure_enum, char const*, int, char const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "verify_gimple_assign_ternary" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "verify_gimple_in_seq_2" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "verify_gimple_in_seq(gimple*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_function_todo" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_todo" "${OUTPUT}" ; then
  exit 1
fi
exit 0