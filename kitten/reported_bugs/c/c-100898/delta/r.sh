#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in gimple_call_arg_ptr, at gimple.h" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_call_arg_ptr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "copy_bb" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "copy_cfg_body" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "copy_body" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_call_inline" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_expand_calls_inline" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "optimize_inline_calls(tree_node*)" "${OUTPUT}" ; then
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