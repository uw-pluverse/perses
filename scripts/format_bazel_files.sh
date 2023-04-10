#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

source "./scripts/constants.sh"
readonly TOOL="@com_github_bazelbuild_buildtools//:buildifier"

# Using load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
# does not work if we have submodules that are very large and contain BUILD files.
# We need to explicitly specify which directories to format BUILD files.
# bazel run //:buildifier

bazel run "${TOOL}" -- ${ABS_BAZEL_DIRS_STRING} \
  "${WORKSPACE_ROOT}/BUILD" \
  "${WORKSPACE_ROOT}/WORKSPACE"
