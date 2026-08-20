#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

if [[ "$#" != 5 ]]; then
  echo "${0} <java path> <adhoc generator> <grammar file> <yaml config> <perses bin>"
  exit 1
fi

readonly JAVA_PATH_ARG=${1}

# Resolve the Java binary path from the Bazel toolchain
if [[ -f "${JAVA_PATH_ARG}" ]]; then
    readonly JAVA=$(realpath "${JAVA_PATH_ARG}")
else
    # Strip 'external/' prefix and look in the parent (runfiles root) directory
    readonly JAVA=$(realpath "../${JAVA_PATH_ARG#external/}")
fi

readonly BIN_ADHOC=${2}
readonly FILE_GRAMMAR=${3}
readonly FILE_YAML=${4}
readonly BIN_PERSES="$(realpath "${5}")"


readonly ROOT=$(mktemp -d)
trap 'rm -rf ${ROOT}' EXIT

readonly FILE_JAR="${ROOT}/ext_language.jar"
# generate the language jar file

"${JAVA}" -jar "${BIN_ADHOC}" \
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
"${JAVA}" -jar "${BIN_PERSES}" \
  --test-script "${FILE_SCRIPT}" \
  --input-file "${FILE_SOURCE}" \
  --language-ext-jars "${FILE_JAR}" || exit 1
cd "perses_result" || exit 1
grep "int" && exit 1
exit 0
