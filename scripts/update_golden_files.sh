#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

# The following array should be computed with `bazel query`.
readonly GOLDEN_TESTS=($(bazel query "attr(tags, 'golden_file_update_target', //...)"))

bazel_build_targets=""
for target in "${GOLDEN_TESTS[@]}" ; do
  bazel_build_targets="${bazel_build_targets} ${target}"
done
# We build all targets at once so as to leverage the multi cores.
# Note that the target list should NOT be quotes, as it contains whitespaces.
# shellcheck disable=SC2086
bazel build ${bazel_build_targets} || exit 1

for target in "${GOLDEN_TESTS[@]}" ; do
  bazel run "${target}"
done