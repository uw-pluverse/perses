#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in gimplify_expr, at gimplify.c" "${OUTPUT}" ; then
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

if ! grep --quiet --fixed-strings "gimplify_bind_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_and_add(tree_node*, gimple**)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_and_return_first" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_transaction" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_return_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_statement_list" "${OUTPUT}" ; then
  exit 1
fi
exit 0