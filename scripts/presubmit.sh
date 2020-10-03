#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

./scripts/check_prerequisite.sh || exit 1

./scripts/check_copyright.sh || exit 1

./scripts/format_bazel_files.sh || exit 1

./scripts/run_ktlint.sh || exit 1

bazel test \
    //test/... \
    //copyright/... \
    //version/... \
    //benchmark/toys/delta_1/... \
    //benchmark/toys/parentheses/... 


"$@"
