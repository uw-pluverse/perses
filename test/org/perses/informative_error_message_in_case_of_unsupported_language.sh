#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ "${#}" != 1 ]] ; then
  echo "$0 <perses_deploy.jar>"
  exit 1
fi

readonly BIN_PERSES="$(realpath "${1}")"
readonly ROOT=$(mktemp -d)
trap 'rm -rf ${ROOT}' EXIT

cd "${ROOT}" || exit 1
readonly FILE_SOURCE="${ROOT}/a.non_existent_language"
touch "${FILE_SOURCE}"
readonly FILE_SCRIPT="${ROOT}/t.sh"
cat > "${FILE_SCRIPT}" << EOF
#!/usr/bin/env bash
exit 0
EOF
chmod +x "${FILE_SCRIPT}"

readonly FILE_LOG="${ROOT}/log.txt"
java -jar "${BIN_PERSES}" --test-script "${FILE_SCRIPT}" --input-file "${FILE_SOURCE}" > "${FILE_LOG}" 2>&1 || true
if grep "Failed to detect the language kind for" "${FILE_LOG}" && \
   grep "The available languages are listed below" "${FILE_LOG}" ; then
  exit 0
else
  echo "no informative error message was printed out."
  cat "${FILE_LOG}"
  exit 1
fi