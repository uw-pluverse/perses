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

if ! grep --quiet --fixed-strings "cgraph_update_edges_for_call_stmt(gimple*, tree_node*, gimple*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_marked_statements" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_function_versioning(tree_node*, tree_node*, vec<ipa_replace_map*, va_gc, vl_embed>*, ipa_param_adjustments*, bool, bitmap_head*, basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "save_inline_function_body" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "inline_transform(cgraph_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_one_ipa_transform_pass" "${OUTPUT}" ; then
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