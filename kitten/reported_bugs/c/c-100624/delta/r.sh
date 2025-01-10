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

if ! grep --quiet --fixed-strings "gimplify_target_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_expr(tree_node**, gimple**, gimple**, bool (*)(tree_node*), int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_stmt(tree_node**, gimple**)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_statement_list" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_compound_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_modify_expr_rhs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_modify_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_and_add(tree_node*, gimple**)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_decl_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_bind_expr" "${OUTPUT}" ; then
  exit 1
fi
exit 0