#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

source "${SCRIPT_DIR}/constants.sh" || exit 1

"${SCRIPT_DIR}/check_prerequisite.sh" || exit 1

"${SCRIPT_DIR}/check_copyright.sh" --update || exit 1

"${SCRIPT_DIR}/format_bazel_files.sh" || exit 1

"${SCRIPT_DIR}/run_ktlint.sh" || exit 1

echo "Clean up is finished successfully."
