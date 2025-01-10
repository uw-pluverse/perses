#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in loc_list_from_tree_1, at dwarf2out.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "loc_list_from_tree_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "loc_list_from_tree" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "add_scalar_info" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "add_subscript_info" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gen_array_type_die" "${OUTPUT}" ; then
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

if ! grep --quiet --fixed-strings "dwarf2out_type_decl" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "rest_of_decl_compilation(tree_node*, int, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "finish_decl(tree_node*, unsigned int, tree_node*, tree_node*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "grokdeclarator" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "push_parm_decl(c_parm const*, tree_node**)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_parms_list_declarator" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_parser_parms_declarator" "${OUTPUT}" ; then
  exit 1
fi
exit 0