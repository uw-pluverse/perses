#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o xtrace
set -o errexit

if [[ "$#" != 1 ]] ; then
  echo "Usage: $0 <install dir>"
  exit 1
fi


readonly TOOLS=("pkg-config"
    "autoconf" 
    "bison" 
    "re2c")

missing=""
for tool in "${TOOLS[@]}" ; do
  if ! command -v "${tool}" &> /dev/null ; then
    missing="${missing} ${tool}"
  fi
done

if [[ "${missing}" != "" ]] ; then
  echo "The following tools are missing: ${missing}"
  exit 1
fi

readonly BUILDROOT="$(mktemp -d)"
[[ "${BUILDROOT}" == "" ]] && exit 1
trap "rm -rf ${BUILDROOT}" EXIT

readonly HOME_USR_BIN="${HOME}/usr/bin"
function cleanup() {
  rm -rf "${BUILDROOT}" &> /dev/null || true
}
trap cleanup EXIT


readonly INSTALLROOT="$(readlink -f $1)"
echo "Installing to ${INSTALLROOT}"
readonly NCPUS="4"

if ! [ -d "${HOME_USR_BIN}" ]; then
  mkdir "${HOME_USR_BIN}"
fi

cd "${BUILDROOT}"
rm -rf * || true
git clone --depth 1 https://github.com/php/php-src.git

readonly SRC_FOLDER="${BUILDROOT}/php-src"

cd "${SRC_FOLDER}"
./buildconf
./configure --enable-debug --prefix=${INSTALLROOT}
make -j4
make install

cd "${HOME_USR_BIN}"
ln -s "${INSTALLROOT}/bin/php" "php-trunk"
./php-trunk -v
