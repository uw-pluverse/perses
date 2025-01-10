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

java -Xmx210G -Xms30G -jar bazel-bin/kitten/src/org/perses/fuzzer/kira_deploy.jar \
  --testing-config "${SCRIPT_DIR}/../clang-clean.yaml" \
  --random-seed 1 \
  --threads 1 \
  --timeout 1800 \
  --shuffle-seed false \
  --verbosity "INFO" \
  --finding-folder "${FINDING_FOLDER}" \
  --seed-limit 1000
