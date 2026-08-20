#!/usr/bin/env bash

set -o nounset
set -o pipefail

readonly SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
source "${SCRIPT_DIR}/constants.sh" || exit 1

./scripts/cleanup.sh || exit 1

# //benchmark_v2 is listed target by target rather than as //benchmark_v2/...:
# //benchmark_v2/binaries does not load (its BUILD globs jdtls-1.33.0 and jdk21, which
# are fetched on demand by install_*.sh and are absent in a clean checkout), so a
# //benchmark_v2/... pattern would fail presubmit outright.
readonly test_command="bazelisk test --test_output=errors \
  --test_tag_filters=-super_slow_parser_test \
  ${ALL_BAZEL_BUILD_TARGETS_STRING} \
  //benchmark_v2:all \
  //benchmark_v2/test:all \
  //:all"

# Regenerate goldens only for the golden tests that actually failed, parsed from a captured test
# log. A failed test is a golden test iff it has a sibling `<target>_update` target tagged
# `golden_file_update_target` (see the golden_test macro in test/test.bzl). Non-golden failures are
# left untouched -- regenerating every golden on any failure is unnecessary and slow, and the rerun
# below still surfaces a genuine failure.
regenerate_goldens_for_failed_tests() {
  local log="${1}"
  local failed_targets
  failed_targets=$(grep -E '^//[^ ]+ +(FAILED|TIMEOUT)' "${log}" | awk '{print $1}' | sort --unique) || true
  local target update_target
  for target in ${failed_targets}; do
    update_target="${target}_update"
    if bazelisk query "attr(tags, 'golden_file_update_target', ${update_target})" 2> /dev/null \
      | grep --quiet .; then
      echo "Regenerating the golden for failed test ${target} via ${update_target}."
      bazelisk run "${update_target}"
    fi
  done
}

readonly test_log="$(mktemp)"
trap 'rm -f "${test_log}"' EXIT

# Capture the test output (to detect which tests failed) while still streaming it to the console.
# errexit is disabled only around the pipeline so a test failure does not abort the script before we
# can react; PIPESTATUS[0] is the test command's own status, independent of tee's.
set +o errexit
${test_command} 2>&1 | tee "${test_log}"
readonly test_status="${PIPESTATUS[0]}"
set -o errexit

if [[ "${test_status}" -ne 0 ]]; then
  echo "The test failed. Regenerating goldens for any failed golden tests."
  regenerate_goldens_for_failed_tests "${test_log}"
  echo "rerunning the tests."
  # Fail if the rerun still fails; otherwise a genuinely broken test (one that updating
  # the golden files does not fix) would be masked by the success banner below.
  ${test_command} || exit 1
fi

# No separate `bazelisk build` is needed here: `--build_tests_only` defaults to
# false, so the `bazelisk test` invocation above already builds every target
# matched by ${ALL_BAZEL_BUILD_TARGETS_STRING} (non-test targets included), which
# is a subset of its patterns. A standalone build over the same patterns would
# be a no-op. Build failures of non-test targets therefore still fail presubmit.
./scripts/build-binaries.sh || exit 1

"$@"

echo "============================================"
echo "The presubmit finished successfully."
echo "============================================"
