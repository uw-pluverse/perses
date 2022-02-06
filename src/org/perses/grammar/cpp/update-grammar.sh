#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit
set -o xtrace

readonly LEXER_URL="https://raw.githubusercontent.com/antlr/grammars-v4/master/cpp/CPP14Lexer.g4"
readonly PARSER_URL="https://raw.githubusercontent.com/antlr/grammars-v4/master/cpp/CPP14Parser.g4"

rm -rf "CPP14Lexer.g4" "CPP14Parser.g4" &> /dev/null || true

wget "${LEXER_URL}"
wget "${PARSER_URL}"
