#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly GOLDEN=$1
readonly REAL=$2

echo "cwd: $(pwd)" 1>&2
echo "golden: ${GOLDEN}" 1>&2
echo "real: ${REAL}" 1>&2

if [[ "${GOLDEN}" == "${REAL}" ]] ; then
  echo "Both files point to the same file. ${GLODEN}" 1>&2
  exit 1
fi
# DO NOT USE --side-by-side. Diff does not return 1 if there is a difference.
diff "${GOLDEN}" "${REAL}"
