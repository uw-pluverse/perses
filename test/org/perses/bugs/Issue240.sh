#!/usr/bin/env bash

set -o xtrace
set -o pipefail
set -o nounset
set -o errexit

# If the bug 240 is not fixed, then this script will not terminate.

[[ "$#" == 1 ]] || exit 1

readonly PERSES_BIN="${1}"

readonly TEMP=$(mktemp -d)
trap "rm -f ${TEMP} || true" EXIT

readonly FILE="${TEMP}/t.c"
echo "a" > "${FILE}"

readonly SCRIPT="${TEMP}/r.sh"
echo "#!/usr/bin/env bash" > "${SCRIPT}"
chmod +x "${SCRIPT}"

java -jar "${PERSES_BIN}" --test-script "${SCRIPT}" --input-file "${FILE}" || true

exit 0