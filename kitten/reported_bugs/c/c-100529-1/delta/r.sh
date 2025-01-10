#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in force_constant_size, at gimplify.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "force_constant_size" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_add_tmp_var(tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "create_tmp_var(tree_node*, char const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "create_tmp_from_val" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lookup_tmp_var" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal_get_tmp_var" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimplify_expr(tree_node**, gimple**, gimple**, bool (*)(tree_node*), int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_regimplify_operands(gimple*, gimple_stmt_iterator*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "insert_init_stmt" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_function_versioning(tree_node*, tree_node*, vec<ipa_replace_map*, va_gc, vl_embed>*, ipa_param_adjustments*, bool, bitmap_head*, basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "cgraph_node::materialize_clone()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_all_ipa_transforms(bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "cgraph_node::expand()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_all_functions" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::compile()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::finalize_compilation_unit()" "${OUTPUT}" ; then
  exit 1
fi
exit 0