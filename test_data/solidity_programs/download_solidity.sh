#!/usr/bin/env bash

set -o xtrace
set -o nounset
set -o errexit
set -o pipefail

readonly GITHUB="git@github.com:ethereum/solidity.git"
readonly DIR_NAME="solidity"

rm -rf "${DIR_NAME}" || true

git clone --depth 1 "${GITHUB}"
readonly TEMP_NAME="temp"
mv "${DIR_NAME}" "${TEMP_NAME}"

rsync --recursive --progress --prune-empty-dirs \
  --include "*/"  --include="*.sol" --exclude="*" \
  "${TEMP_NAME}/" "${DIR_NAME}"

cp "${TEMP_NAME}/LICENSE.txt" "${DIR_NAME}"
rm -rf "${TEMP_NAME}"
