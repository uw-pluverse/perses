#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

if [[ "$#" != 4 ]] ; then
  echo "${0} <adhoc generator> <grammar file> <yaml config> <perses bin>"
  exit 1
fi

readonly BIN_ADHOC=${1}
readonly FILE_GRAMMAR=${2}
readonly FILE_YAML=${3}
readonly BIN_PERSES="$(realpath "${4}")"

readonly ROOT=$(mktemp -d)
trap 'rm -rf ${ROOT}' EXIT

readonly FILE_JAR="${ROOT}/ext_language.jar"
# generate the language jar file

java -jar "${BIN_ADHOC}" \
  --parser-grammar "${FILE_GRAMMAR}" \
  --start-rule "translationUnit" \
  --token-names-of-identifiers "Identifier" \
  --package-name "test.adhoc.language" \
  --language-kind-yaml-file "${FILE_YAML}" \
  --output "${FILE_JAR}" || exit 10

[ -f "${FILE_JAR}" ] || exit 20

readonly FILE_SOURCE="${ROOT}/t.test"
echo "int var = 0;" > "${FILE_SOURCE}"

readonly FILE_SCRIPT="${ROOT}/r.sh"
cat > "${FILE_SCRIPT}" << EOF
#!/usr/bin/env bash

grep "var" "t.test"
EOF
chmod +x "${FILE_SCRIPT}"

cd "${ROOT}" || exit 1
java -jar "${BIN_PERSES}" \
    --test-script "${FILE_SCRIPT}" \
    --input-file "${FILE_SOURCE}" \
    --language-ext-jars "${FILE_JAR}" || exit 1
cd "perses_result" || exit 1
grep "int" && exit 1
exit 0