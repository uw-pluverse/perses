#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

source "./scripts/constants.sh"
readonly TOOL="@com_github_bazelbuild_buildtools//:buildifier"

bazelisk run "${TOOL}" -- ${WORKSPACE_ROOT}/"perses-fuzzer"
