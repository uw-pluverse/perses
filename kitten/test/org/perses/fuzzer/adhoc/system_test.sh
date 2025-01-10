#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

if [[ "$#" != 4 ]] ; then
  echo "${0} <adhoc generator> <grammar file> <yaml config> <fuzzer bin>"
  exit 1
fi

readonly BIN_ADHOC=${1}
readonly FILE_GRAMMAR=${2}
readonly FILE_YAML=${3}
readonly BIN_FUZZER="$(realpath "${4}")"

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

# create seed files
readonly SEED_DIR="${ROOT}/seeds/"
mkdir -p "${SEED_DIR}" || true
echo "int i;" > "${SEED_DIR}/t1.test"

# generate the mock compiler
readonly MOCK_FILE="${ROOT}/mock_compiler.sh"
cat > "${MOCK_FILE}" << 'EOF'
#!/usr/bin/env bash
if [[ "${1}" == "-v" ]] ; then
  echo "mock script"
  exit 0
fi
echo "t.test: internal compiler error:" 1>&2
exit 137
EOF
chmod +x "${MOCK_FILE}"

# generate the testing config yaml file
readonly CONFIG_FILE="${ROOT}/testing-config.yaml"
cat > "${CONFIG_FILE}" << EOF
language: "test_lang"
seedFolders:
  - path: "${SEED_DIR}"
    fileExtentions: [".test"]

programsUnderTest:
  - command: "${MOCK_FILE}"
    flagsToTest:
      - flags: []
    versionFlags:
      flags: ["-v"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.c.GccCrashDetector"

EOF

cat "${CONFIG_FILE}"

# launch the fuzzer
readonly FINDING_DIR="${ROOT}/findings"
mkdir -p "${FINDING_DIR}" || true

readonly BUGS_FOUND_BEFORE=$(grep "internal compiler error:" "${FINDING_DIR}"/* -R | wc --lines)
[[ "${BUGS_FOUND_BEFORE}" == 0 ]] || exit 1

cd "${ROOT}" || exit 1
java -jar "${BIN_FUZZER}" \
  --threads 1 \
  --random-seed 1 \
  --shuffle-seed false \
  --max-iterations 1 \
  --verbosity "FINE" \
  --finding-folder "${FINDING_DIR}" \
  --testing-config "${CONFIG_FILE}" \
  --language-ext-jars "${FILE_JAR}"

readonly BUGS_FOUND_AFTER=$(grep "internal compiler error:" "${FINDING_DIR}"/* -R | wc --lines)
[[ "${BUGS_FOUND_AFTER}" != 0 ]] || exit 1
