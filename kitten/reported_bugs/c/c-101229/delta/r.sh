#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in vect_get_vec_defs_for_operand, at tree-vect-stmts.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_get_vec_defs_for_operand(vec_info*, _stmt_vec_info*, unsigned int, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_get_vec_defs(vec_info*, _stmt_vec_info*, _slp_tree*, unsigned int, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_get_vec_defs(vec_info*, _stmt_vec_info*, _slp_tree*, unsigned int, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*, vec<tree_node*, va_heap, vl_ptr>*, tree_node*, vec<tree_node*, va_heap, vl_ptr>*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vectorizable_lc_phi(_loop_vec_info*, _stmt_vec_info*, gimple**, _slp_tree*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_transform_stmt(vec_info*, _stmt_vec_info*, gimple_stmt_iterator*, _slp_tree*, _slp_instance*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_transform_loop(_loop_vec_info*, gimple*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "try_vectorize_loop_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vectorize_loops()" "${OUTPUT}" ; then
  exit 1
fi
exit 0