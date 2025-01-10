#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in recompute_tree_invariant_for_addr_expr, at tree.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "recompute_tree_invariant_for_addr_expr(tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_addr_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_expr(tree_node**, gimple**, gimple**, bool (*)(tree_node*), int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_modify_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_stmt(tree_node**, gimple**)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_statement_list" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_bind_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_body(tree_node*, bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_function_tree(tree_node*)" "${OUTPUT}" ; then
  exit 1
fi
exit 0