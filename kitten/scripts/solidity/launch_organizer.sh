#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
source "${SCRIPT_DIR}/configuration.sh" || exit 1

bazelisk build //kitten/src/org/perses/fuzzer/organizer:main_deploy.jar || exit 1

java -jar bazel-bin/kitten/src/org/perses/fuzzer/organizer/main_deploy.jar \
  --lang SOLIDITY \
  --finding-folder "${FINDING_FOLDER}" \
  --processing-folder "${PROCESSING_FOLDER}" \
  --duplicate-folder "${DUPLICATE_FOLDER}" \
  --reported-folder "${REPORTED_FOLDER}"
