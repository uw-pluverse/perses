#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ $# != 1 ]] ; then
  echo "$0 <perses_bin_path>"
  exit 1
fi

readonly PERSES_BIN="${1}"

readonly ROOT=$(mktemp -d)
trap "rm -rf ${ROOT}" EXIT

readonly DATA_DIR="${ROOT}/data"
readonly SRC_DIR="${ROOT}/src/"
mkdir -p "${SRC_DIR}"
mkdir -p "${DATA_DIR}"

readonly REDUCTION_SCRIPT="${SRC_DIR}/r.sh"
cat << EOF > "${REDUCTION_SCRIPT}"
#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [ ! -d "${DATA_DIR}" ] ; then
  echo "${DATA_DIR} does not exist."
  exit 100
fi

readonly FILE_COUNT=\$(ls -A "${DATA_DIR}" | wc -l)
touch "${DATA_DIR}/\${FILE_COUNT}.txt"
if (( FILE_COUNT % 2 == 0 )) ; then
  exit 1
else
  exit 0
fi

EOF
chmod +x "${REDUCTION_SCRIPT}"

readonly SOURCE_FILE="${SRC_DIR}/t.c"
echo "int a;" > "${SOURCE_FILE}"

readonly LOG_FILE="${ROOT}/log.txt"
${PERSES_BIN} --test-script "${REDUCTION_SCRIPT}" --input-file "${SOURCE_FILE}" &> "${LOG_FILE}" || true
if grep --quiet "The property test is flaky. #total runs: 6, #interesting: 3, #uninteresting: 3" "${LOG_FILE}" ; then
  exit 0
else
  grep "flaky" "${LOG_FILE}"
  exit 1
fi

