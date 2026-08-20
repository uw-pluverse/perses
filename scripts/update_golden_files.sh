#!/usr/bin/env bash

# constants.sh sets errexit/nounset/pipefail, cds to the workspace root, and
# computes the set of bazel directories to operate on (ALL_BAZEL_BUILD_TARGETS).
# It excludes the //benchmark* trees, whose glob-based package loading fails when
# their large binary artifacts are absent from a checkout -- which would
# otherwise abort the `//...` query below.
source "$(dirname "${BASH_SOURCE[0]}")/constants.sh"

# Union the directory roots into a single query universe. The bazel query
# expression language requires '+' between patterns, not spaces. `//:all` covers
# root-package golden targets (e.g. the top-level README golden), which the
# per-directory `//dir/...` patterns in ALL_BAZEL_BUILD_TARGETS do not match.
query_universe="//:all"
for target in "${ALL_BAZEL_BUILD_TARGETS[@]}"; do
  query_universe="${query_universe} + ${target}"
done

readonly GOLDEN_TESTS=($(bazelisk query "attr(tags, 'golden_file_update_target', ${query_universe})"))

# Every argument to this script is forwarded to bazel, so a machine that is busy with
# other work can cap the load: ./scripts/update_golden_files.sh --jobs=4
# The flags go before the target because anything after it is passed to the target itself.
readonly BAZEL_FLAGS=("$@")

# We build all targets at once so as to leverage the multi cores.
# Note that the target list should NOT be quoted, as it contains whitespaces.
# shellcheck disable=SC2086
bazelisk build "${BAZEL_FLAGS[@]}" ${GOLDEN_TESTS[*]} || exit 1

for target in "${GOLDEN_TESTS[@]}"; do
  bazelisk run "${BAZEL_FLAGS[@]}" "${target}"
done
