#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

"ktlint" --format \
    "src/**/*.kt" \
    "test/**/*.kt" \
    "antlropt/**/*.kt" \
    "version/**/*.kt"