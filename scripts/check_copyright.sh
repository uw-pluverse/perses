#!/usr/bin/env bash

set -o nounset
set -o pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source "${SCRIPT_DIR}/constants.sh" || exit 1

COPYRIGHT_FILEPATH="./copyright/copyright.txt"

if ! bazel run //copyright:check_copyright_main -- \
    "$@" "${WORKSPACE_ROOT}/${COPYRIGHT_FILEPATH}" ${ABS_BAZEL_DIRS_STRING} ; then
  echo "Run '$0 --update-copyright' to fix this problem"
  exit 1
fi

exit 0
