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

if ! grep --quiet --fixed-strings "gimple_builtin_call_types_compatible_p(gimple const*, tree_node*)" "${OUTPUT}" ; then
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