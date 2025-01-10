#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: ‘verify_type’ failed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "verify_type(tree_node const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gen_type_die_with_usage" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gen_type_die" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gen_decl_die" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "dwarf2out_decl" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "dwarf2out_early_global_decl" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "finish_decl(tree_node*, unsigned int, tree_node*, tree_node*, tree_node*)" "${OUTPUT}" ; then
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