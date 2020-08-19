#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

if [[ "$#" != 1 ]] ; then
  echo "ERROR: Usage: $0 <install dir>"
  exit 1
fi

if [[ ! -d "${1}" ]] ; then
  echo "ERROR: ${1} is not a directory"
  exit 1
fi
readonly INSTALL_DIR="$( cd "${1}" &> /dev/null && pwd )"

# Update the repo.
git pull || true

readonly JAR_NAME="perses_deploy.jar"
readonly TARGET="//src/org/perses:${JAR_NAME}"
bazel build "${TARGET}"

readonly JAR_PATH="bazel-bin/src/org/perses/${JAR_NAME}"
readonly INSTALLED_JAR_PATH="${INSTALL_DIR}/${JAR_NAME}"
cp "${JAR_PATH}" "${INSTALL_DIR}"

readonly INSTALLED_SCRIPT="${INSTALL_DIR}/perses"
cat > "${INSTALLED_SCRIPT}" << EOF
#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

readonly JAR="${INSTALLED_JAR_PATH}"
java -jar "\${JAR}" \$@

EOF
chmod +x "${INSTALLED_SCRIPT}"

echo "Perses is successfully installed in ${INSTALL_DIR}. The command name is 'perses'."
