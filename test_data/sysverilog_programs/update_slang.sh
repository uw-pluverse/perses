#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit
set -o xtrace

readonly DIR="Surelog"
readonly URL="git@github.com:alainmarcel/${DIR}.git"

rm -rf "${DIR}" || true
git clone --depth 1 "${URL}"

(
  cd "${DIR}"
  rm -rf .* &> /dev/null || true
  rm -rf CMakeLists.txt Makefile grammar/build.xml
)