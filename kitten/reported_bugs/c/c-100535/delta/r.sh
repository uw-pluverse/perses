#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: tree check: expected function_type or method_type, have integer_type in gimplify_call_expr, at gimplify.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_check_failed(tree_node const*, char const*, int, char const*, ...)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_check2(tree_node*, char const*, int, char const*, tree_code, tree_code)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_call_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_expr(tree_node**, gimple**, gimple**, bool (*)(tree_node*), int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "force_gimple_operand_1(tree_node*, gimple**, bool (*)(tree_node*), tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_and_update_call_from_tree(gimple_stmt_iterator*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_fold_builtin" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_fold_call" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_stmt_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_stmt" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_sequence" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_gimple_bind" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_function_body" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0