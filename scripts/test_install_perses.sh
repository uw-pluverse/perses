#!/usr/bin/env bash
#
# This is the test for install_perses.sh
#
set -o pipefail
set -o nounset
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly TMP="$(mktemp -d)"
trap "rm -rf ${TMP}" EXIT

readonly DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
readonly INSTALL_SCRIPT="${DIR}/install_perses.sh"

bash -x "${INSTALL_SCRIPT}" "${TMP}"
ls ${TMP}

readonly HELP_FILE="${TMP}/help.txt"
"${TMP}/perses" "--help" &> "${HELP_FILE}"
grep "Usage: org.perses.Main" "${HELP_FILE}"




