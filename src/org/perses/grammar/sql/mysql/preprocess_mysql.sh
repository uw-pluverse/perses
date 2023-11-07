#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit
set -o xtrace

readonly RDC="antlrrdc/src/org/perses/antlr/reducer"
readonly MAIN_TARGET="//antlrrdc/src/org/perses/antlr/reducer:main"

bazel build "${MAIN_TARGET}"

readonly WORKSPACE_ROOT="$(bazel info | grep "workspace: " | awk '{print $2}')"


[[ -f "${WORKSPACE_ROOT}/WORKSPACE" ]] || exit 1

readonly CORPUS_DIR="${WORKSPACE_ROOT}/test_data/mysql_programs/"

readonly CURRENT_DIR="$(pwd)"
readonly PARSER="${CURRENT_DIR}/MySqlParser.g4"
readonly LEXER="${CURRENT_DIR}/MySqlLexer.g4"
readonly OUTPUT_DIR="${CURRENT_DIR}/preprocessed"
readonly START_RULE_NAME="root"

bazel build "${MAIN_TARGET}"
bazel run "${MAIN_TARGET}" -- \
  --parser "${PARSER}" \
  --lexer "${LEXER}" \
  --start "${START_RULE_NAME}" \
  --corpus "${CORPUS_DIR}" \
  --file-ext ".mysql" \
  --output-dir "${OUTPUT_DIR}"

rm "${OUTPUT_DIR}/r.sh" "${OUTPUT_DIR}"/*.jar