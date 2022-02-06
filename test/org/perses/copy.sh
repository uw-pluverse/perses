#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly SOURCE=$1
readonly DESC=$2

echo "cwd: $(pwd)" 1>&2
echo "src: ${SOURCE}" 1>&2
echo "desc: ${DESC}" 1>&2

if [[ "${SOURCE}" == "${DESC}" ]] ; then
  echo "Both files point to the same file. ${DESC}" 1>&2
  exit 1
fi

if cp "${SOURCE}" "${DESC}" ; then
  echo "==Success=="
else
  echo "==Failure=="
fi
