#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o xtrace
set -o errexit

if [[ "$#" != 1 ]] ; then
  echo "Usage: $0 <install dir>"
  exit 1
fi

readonly BUILDROOT="$(mktemp -d)"
[[ "${BUILDROOT}" == "" ]] && exit 1

readonly SRC_FOLDER="${BUILDROOT}/dotty/"
readonly HOME_USR_BIN="${HOME}/usr/bin"

function cleanup() {
  rm -rf "${BUILDROOT}" &> /dev/null || true
}
trap cleanup EXIT

readonly INSTALLROOT="$(readlink -f $1)"
echo "Installing to ${INSTALLROOT}"
readonly NCPUS="1"

cd "${BUILDROOT}"

rm -rf "${SRC_FOLDER}" || true # &> /dev/null
# Have to use svn checkout, so that the commit id can appear in the gcc -v.
git clone --depth 1 https://github.com/lampepfl/dotty.git || exit 1
[[ -d "${SRC_FOLDER}" ]] || exit 1

cd "${SRC_FOLDER}"
# trigger the build of scalac
./bin/scalac --version

INSTALL_DIR="${INSTALLROOT}/scala_dotty"
rm -rf "${INSTALL_DIR}"
mv  "${SRC_FOLDER}" "${INSTALL_DIR}"

ABS_SCALAC="${INSTALL_DIR}/bin/scalac"

SCALAC_LINK="${HOME_USR_BIN}/scalac-trunk"

cat > "${SCALAC_LINK}" << EOF
#!/usr/bin/env bash

${ABS_SCALAC} "\$@"
EOF

chmod +x "${SCALAC_LINK}"

