#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "print_type" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "c_tree_printer" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "pp_format(pretty_printer*, text_info*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "diagnostic_report_diagnostic(diagnostic_context*, diagnostic_info*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "diagnostic_impl" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "warning(int, char const*, ...)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "positional_argument(tree_node const*, tree_node const*, tree_node*, tree_code, int, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "handle_nonnull_attribute" "${OUTPUT}" ; then
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