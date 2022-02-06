#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit
set -o xtrace

readonly RDC="antlrrdc/src/org/perses/antlr/reducer"
readonly MAIN_TARGET="//antlrrdc/src/org/perses/antlr/reducer:main"

bazel build "${MAIN_TARGET}"

readonly WORKSPACE_ROOT="$(cd ../../../../../ ; pwd)"


[[ -f "${WORKSPACE_ROOT}/WORKSPACE" ]] || exit 1

readonly CORPUS_DIR="${WORKSPACE_ROOT}/test_data/solidity_programs/"

readonly CURRENT_DIR="$(pwd)"
readonly PARSER="${CURRENT_DIR}/Solidity.g4"
readonly LEXER="${CURRENT_DIR}/SolidityLexer.g4"
readonly OUTPUT_DIR="${CURRENT_DIR}/preprocessed"

bazel build "${MAIN_TARGET}"
bazel run "${MAIN_TARGET}" -- \
  --parser "${PARSER}" \
  --lexer "${LEXER}" \
  --start "sourceUnit" \
  --corpus "${CORPUS_DIR}" \
  --file-ext ".sol" \
  --output-dir "${OUTPUT_DIR}"

rm "${OUTPUT_DIR}/r.sh" "${OUTPUT_DIR}/Solidity.jar"