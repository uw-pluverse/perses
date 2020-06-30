#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

./scripts/format_bazel_files.sh

./scripts/run_ktlint.sh

bazel test \
    //test/... \
    //copyright/... \
    //fuzzer_test/... \
    //benchmark/toys/delta_1/... \
    //benchmark/toys/go_print/... \
    //benchmark/toys/parentheses/... \
    //benchmark/toys/rs_print/... \
    //benchmark/toys/scala_print/...

"$@"