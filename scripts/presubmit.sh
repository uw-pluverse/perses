#!/usr/bin/env bash

set -o nounset
set -o pipefail

readonly SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
source "${SCRIPT_DIR}/constants.sh" || exit 1

./scripts/cleanup.sh || exit 1

readonly test_command="bazelisk test --test_output=errors \
  --test_tag_filters=-super_slow_parser_test \
  ${ALL_BAZEL_BUILD_TARGETS_STRING} \
  //benchmark:run_benchmark_test \
  //benchmark:convert_memory_log_to_csv_test \
  //benchmark:convert_time_query_to_csv_test \
  //:all"

if ! ${test_command} ; then
  echo "The test failed. Trying to update the golden files."
  ./scripts/update_golden_files.sh || exit 1
  echo "rerunning the tests."
  ${test_command}
fi

# Run the build later, because test takes more time and needs parallelism.
# Note that `bazelisk build` builds more targets than `bazelisk test`
bazelisk build ${ALL_BAZEL_BUILD_TARGETS_STRING} || exit 1

"${SCRIPT_DIR}/run_spotbugs_on_perses_deploy_jar.sh" || exit 1

"$@"

echo "============================================"
echo "The presubmit finished successfully."
echo "============================================"
