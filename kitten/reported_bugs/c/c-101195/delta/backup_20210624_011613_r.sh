#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in tree_to_uhwi, at tree.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_to_uhwi(tree_node const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin_eh_return_data_regno(tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin(tree_node*, rtx_def*, rtx_def*, machine_mode, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_expr_real_1(tree_node*, rtx_def*, machine_mode, expand_modifier, rtx_def**, bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "store_expr(tree_node*, rtx_def*, int, bool, bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_assignment(tree_node*, tree_node*, bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_call_stmt" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_gimple_stmt_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_gimple_stmt" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_gimple_basic_block" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0