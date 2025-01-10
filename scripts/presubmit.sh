#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

readonly SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source "${SCRIPT_DIR}/constants.sh" || exit 1

./scripts/cleanup.sh || exit 1

bazelisk test --test_output=errors ${ALL_BAZEL_BUILD_TARGETS_STRING} \
    //benchmark:run_benchmark_test\
    //benchmark:convert_memory_log_to_csv_test\
    //benchmark:convert_time_query_to_csv_test || exit 1

# Run the build later, because test takes more time and needs parallelism.
# Note that `bazelisk build` builds more targets than `bazelisk test`
bazelisk build ${ALL_BAZEL_BUILD_TARGETS_STRING} || exit 1

./scripts/update_golden_files.sh || exit 1

"$@"

echo "============================================"
echo "The presubmit finished successfully."
echo "============================================"
