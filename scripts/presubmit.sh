#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

./scripts/check_prerequisite.sh

./scripts/check_copyright.sh

./scripts/format_bazel_files.sh

./scripts/run_ktlint.sh

bazel test \
    //test/... \
    //copyright/... \
    //version/... \
    //benchmark/toys/delta_1/... \
    //benchmark/toys/parentheses/... 


"$@"
