#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

readonly SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source "${SCRIPT_DIR}/constants.sh" || exit 1
readonly TOOL="@com_github_bazelbuild_buildtools//:buildifier"

# Using load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
# does not work if we have submodules that are very large and contain BUILD files.
# We need to explicitly specify which directories to format BUILD files.
# bazelisk run //:buildifier

bazelisk run -s "${TOOL}" -- \
   -lint fix \
   -r \
   ${ABS_BAZEL_DIRS_STRING} \
  "${WORKSPACE_ROOT}/BUILD" \
  "${WORKSPACE_ROOT}/WORKSPACE"
