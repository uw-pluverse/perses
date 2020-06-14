#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

find . -name "BUILD" | xargs buildifier
find . -name "*.bzl" | xargs buildifier
buildifier WORKSPACE