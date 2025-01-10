#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in try_store_by_multiple_pieces, at builtins.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "try_store_by_multiple_pieces(rtx_def*, rtx_def*, unsigned int, unsigned long, unsigned long, rtx_def*, char, unsigned int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "clear_storage_hints(rtx_def*, rtx_def*, block_op_methods, unsigned int, long, unsigned long, unsigned long, unsigned long, unsigned int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin_memset_args" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin_memset" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_builtin(tree_node*, rtx_def*, rtx_def*, machine_mode, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_expr_real_1(tree_node*, rtx_def*, machine_mode, expand_modifier, rtx_def**, bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_expr" "${OUTPUT}" ; then
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