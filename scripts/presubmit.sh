#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

source "./scripts/constants.sh" || exit 1

./scripts/cleanup.sh || exit 1

bazel test --test_output=errors ${ALL_BAZEL_BUILD_TARGETS_STRING} \
    //benchmark:run_benchmark_test\
    //benchmark:analyze_cache_profiling_test\
    //benchmark:convert_result_to_csv_test || exit 1

# Run the build later, because test takes more time and needs parallelism.
# Note that `bazel build` builds more targets than `bazel test`
bazel build ${ALL_BAZEL_BUILD_TARGETS_STRING} || exit 1

./scripts/update_golden_files.sh || exit 1

"$@"

echo "============================================"
echo "The presubmit finished successfully."
echo "============================================"
