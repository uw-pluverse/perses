#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: tree check: expected class ‘type’, have ‘exceptional’ (error_mark) in useless_type_conversion_p, at gimple-expr.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_class_check_failed(tree_node const*, tree_code_class, char const*, int, char const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_class_check(tree_node*, tree_code_class, char const*, int, char const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "useless_type_conversion_p(tree_node*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "types_compatible_p" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_addr_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_expr(tree_node**, gimple**, gimple**, bool (*)(tree_node*), int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_call_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_stmt(tree_node**, gimple**)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_statement_list" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_cond_expr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_bind_expr" "${OUTPUT}" ; then
  exit 1
fi
exit 0