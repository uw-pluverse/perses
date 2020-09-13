#!/usr/bin/env bash

set -o nounset
set -o pipefail

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly ROOT=$(pwd)
if ! bazel run //copyright:check_copyright_main -- \
    "$@" \
    "${ROOT}/antlropt/" \
    "${ROOT}/src/" \
    "${ROOT}/test/" \
    "${ROOT}/version/" ; then
  echo "Run '$0 -u' to fix this problem"
  exit 1
fi

exit 0
