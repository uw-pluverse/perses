#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in expand_call, at calls.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_call(tree_node*, rtx_def*, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin(tree_node*, rtx_def*, rtx_def*, machine_mode, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_expr_real_1(tree_node*, rtx_def*, machine_mode, expand_modifier, rtx_def**, bool)" "${OUTPUT}" ; then
  exit 1
fi
exit 0