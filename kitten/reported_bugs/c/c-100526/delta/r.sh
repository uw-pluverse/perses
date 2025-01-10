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

if ! grep --quiet --fixed-strings "c_parser_gimple_declaration" "${OUTPUT}" ; then
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