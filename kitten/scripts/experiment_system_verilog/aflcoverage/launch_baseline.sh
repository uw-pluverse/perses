#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
source "${SCRIPT_DIR}/../configuration.sh" || exit 1

bazelisk build //kitten/src/org/perses/fuzzer:kira_deploy.jar || exit 1

java -Xmx75G -Xms30G -Djava.library.path=bazel-bin/kitten/src/org/perses/fuzzer/coveragecollector \
  -jar bazel-bin/kitten/src/org/perses/fuzzer/kira_deploy.jar \
  --testing-config "${SCRIPT_DIR}/../slang-config.yaml" \
  --random-seed 0 \
  --threads 8 \
  --timeout 43200 \
  --shuffle-seed false \
  --verbosity "INFO" \
  --finding-folder "${FINDING_FOLDER}" \
  --afl-coverage-mode true \
  --coverage-interval 60 \
  --coverage-save "${PWD}/kitten/temp_experiment_results/slang_baseline_coverage" \
  --language-model "N_DEPTH_TREE_MODEL" \
  --allow-enable-guidance false \
  --generator "RANDOM_GENERATOR" \
  --seed-limit 20000 2>&1 | tee "${LOG_FILE}"
