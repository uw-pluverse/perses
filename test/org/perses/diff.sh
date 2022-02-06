#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly GOLDEN=$1
readonly ACTUAL=$2

echo "cwd: $(pwd)" 1>&2
echo "golden: ${GOLDEN}" 1>&2
echo "real: ${ACTUAL}" 1>&2

if [[ "${GOLDEN}" == "${ACTUAL}" ]] ; then
  echo "Both files point to the same file. ${GLODEN}" 1>&2
  exit 1
fi
# DO NOT USE --side-by-side. Diff does not return 1 if there is a difference.
diff "${GOLDEN}" "${ACTUAL}" &> /dev/null
readonly EXIT_CODE="$?"

if [[ "${EXIT_CODE}" != 0 ]] ; then
  # Note that the following does not return 1 even if there is a difference.
  echo "=====golden file====="
  cat "${GOLDEN}"
  echo "=====actual file====="
  cat "${ACTUAL}"
  echo "=====concise diff====="
  diff "${GOLDEN}" "${ACTUAL}"
  echo "=====detailed diff====="
  diff --side-by-side "${GOLDEN}" "${ACTUAL}"
  echo ""
  echo "====Test failed.===="
  echo "To fix the golden test, run 'bazel run <this failing test taget name>_update"
else
  echo "====Test passed.===="
fi

exit "${EXIT_CODE}"