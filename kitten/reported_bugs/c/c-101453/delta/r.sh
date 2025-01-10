#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: Aborted" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "crash_signal" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "sprintf" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "parse_optimize_options(tree_node*, bool)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "handle_optimize_attribute" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "decl_attributes(tree_node**, tree_node*, int, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "start_function(c_declspecs*, c_declarator*, tree_node*)" "${OUTPUT}" ; then
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