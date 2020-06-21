#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly ROOT=$(pwd)
bazel run //copyright:check_copyright_main -- \
    "$@" \
    "${ROOT}/antlropt/" \
    "${ROOT}/fuzzer/" \
    "${ROOT}/fuzzer_test/" \
    "${ROOT}/src/" \
    "${ROOT}/test/"