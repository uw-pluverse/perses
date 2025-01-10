#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

./kitten/scripts/check_copyright.sh

./kitten/scripts/format_bazel_files.sh

./kitten/scripts/run_ktlint.sh

bazelisk test \
    //kitten/test/... \

"$@"
