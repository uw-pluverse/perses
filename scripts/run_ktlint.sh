#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

bazel build "//:ktlint_deploy.jar"

# DON'T use 'bazel run //:ktlint_deploy.jar' due to its working directory
#     is not the root of the workspace.
java -jar bazel-bin/ktlint_deploy.jar --format \
    "src/**/*.kt" \
    "test/**/*.kt" \
    "antlropt/**/*.kt" \
    "version/**/*.kt" || exit 1

echo "ktlint is done."