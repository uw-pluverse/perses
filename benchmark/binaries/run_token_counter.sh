#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
#set -o xtrace

#expect
# code to count token of

#do
# run token counter on given file

if [ $# -le 0 ]; then
    echo "Expect arguments $0 SOURCE_FILE"
    exit 1
fi

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly SOURCE_FILE=$1

OUTPUT=$(java -jar "/tmp/binaries/token_counter_deploy.jar" "${SOURCE_FILE}")
readonly RET_CODE="$?"

LASTLINE=$(echo "${OUTPUT}" | tail -n 1)
echo "${LASTLINE}"

exit "${RET_CODE}"
