#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

# https://github.com/DimitrisAndreou/memory-measurer
readonly REPO_NAME="memory-measurer"
readonly URL="https://github.com/DimitrisAndreou/${REPO_NAME}"
git clone "${URL}"

readonly JAR_NAME="object-explorer.jar"
(
  cd "${REPO_NAME}"
  ant
  cp "dist/${JAR_NAME}" "../${JAR_NAME}"
  cp "LICENSE.txt" ..
)
rm -rf "${REPO_NAME}"