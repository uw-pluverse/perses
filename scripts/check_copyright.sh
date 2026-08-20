#!/usr/bin/env bash

set -o nounset
set -o pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
source "${SCRIPT_DIR}/constants.sh" || exit 1
source "${SCRIPT_DIR}/changed_files.sh" || exit 1

COPYRIGHT_FILEPATH="./copyright/copyright.txt"

# By default only the changed files are checked, which keeps presubmit fast.
# Pass --all to scan every source directory in the tree (e.g. for a full sweep).
# Any other flags (e.g. --update) are forwarded to the python tool.
SCAN_ALL=0
TOOL_ARGS=()
for arg in "$@"; do
  if [[ "${arg}" == "--all" ]]; then
    SCAN_ALL=1
  else
    TOOL_ARGS+=("${arg}")
  fi
done

# If the copyright template itself changed, every source file's header may now
# be stale even though the source did not change, so force a full-tree scan.
if [[ "${SCAN_ALL}" -eq 0 ]] \
  && ! git diff --quiet "$(changed_files_base_ref)" -- "${COPYRIGHT_FILEPATH}"; then
  echo "Copyright template ${COPYRIGHT_FILEPATH} changed; scanning all source directories."
  SCAN_ALL=1
fi

if [[ "${SCAN_ALL}" -eq 1 ]]; then
  PATHS=("${ABS_BAZEL_DIRS[@]}")
else
  mapfile -t PATHS < <(collect_changed_files java kt proto)
  if [[ "${#PATHS[@]}" -eq 0 ]]; then
    echo "No changed Java/Kotlin/proto files to check for copyright."
    exit 0
  fi
fi

if ! bazelisk run //copyright:check_copyright_main -- \
  "${TOOL_ARGS[@]}" "${WORKSPACE_ROOT}/${COPYRIGHT_FILEPATH}" "${PATHS[@]}"; then
  echo "Run '$0 --update-copyright' to fix this problem"
  exit 1
fi

exit 0
