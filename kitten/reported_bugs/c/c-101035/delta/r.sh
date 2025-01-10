#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in wide_int_to_tree_1, at tree.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "wide_int_to_tree_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "wide_int_to_tree(tree_node*, poly_int<1u, generic_wide_int<wide_int_ref_storage<false, true> > > const&)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "build_int_cst(tree_node*, poly_int<1u, long>)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "build_simple_mem_ref_loc(unsigned int, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_gimple_postfix_expression_after_primary" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_gimple_postfix_expression" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_gimple_binary_expression" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_gimple_statement" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_gimple_compound_statement" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_parse_gimple_body(c_parser*, char*, c_declspec_il, profile_count)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_declaration_or_fndef" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_external_declaration" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_translation_unit" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parse_file()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_common_parse_file()" "${OUTPUT}" ; then
  exit 1
fi
exit 0