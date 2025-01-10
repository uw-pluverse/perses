#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in build_attr_access_from_parms, at c-family/c-attribs.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "build_attr_access_from_parms(tree_node*, bool)" "${OUTPUT}" ; then
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