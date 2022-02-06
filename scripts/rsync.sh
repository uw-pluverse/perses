#!/usr/bin/env bash

# If you want to use this script, run the following command:
#     cp rsync_host_info.template .rsync_host_info
# and then edit .rsync_host_info by filling the required information.

set -o nounset
set -o pipefail
set -o errexit
set -o xtrace

PULL="false"
ONLY_COPY="false"
if [[ "$#" == 1 ]] ; then
  if [[ "${1}" == "pull" ]] ; then
    PULL="true"
  elif [[ "${1}" == "onlycopy" ]] ; then
    ONLY_COPY="true"
  else
    echo "'pull' or 'onlycopy' is the only allowed argument."
    exit 1
  fi
elif [[ "$#" != 0 ]] ; then
  echo "invalid arguments."
  exit 1
fi

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

source "${DIR}/.rsync_host_info"

readonly OPTIONS="--recursive --compress --progress --archive"

readonly EXCLUDED_FOLDERS=("bazel-bin" \
                           "bazel-out" \
                           "bazel-perses-private" \
                           "bazel-testlogs" \
                           ".ijwb" \
                           )
EXCLUDED_FLAGS=""
for folder in "${EXCLUDED_FOLDERS[@]}" ; do
  EXCLUDED_FLAGS="${EXCLUDED_FLAGS} --exclude ${folder} "
done

# Send to the remote server.
rsync ${OPTIONS} ${EXCLUDED_FLAGS} "$(pwd)/" "${HOST}:${REMOTE_FOLDER}"

if "${ONLY_COPY}" ; then
  exit 0
fi
ssh "${HOST}" -t "cd ${REMOTE_FOLDER}; bash --login"

if "${PULL}" ; then
  # Pull from the remote server.
  rsync ${OPTIONS} ${EXCLUDED_FLAGS} --exclude '.git' "${HOST}:${REMOTE_FOLDER}" "$(pwd)/"
fi
