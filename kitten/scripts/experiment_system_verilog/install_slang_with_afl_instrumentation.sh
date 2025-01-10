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

readonly HOME_USR_BIN="${HOME}/usr/bin"

function cleanup() {
  rm -rf "${BUILDROOT}" &> /dev/null || true
}
trap cleanup EXIT


readonly INSTALLROOT="$(readlink -f $1)"
echo "Installing to ${INSTALLROOT}"
readonly NCPUS="4"

cd "${BUILDROOT}"
rm -rf * || true
# wget https://github.com/MikePopoloski/slang/archive/refs/tags/nightly.tar.gz
# tar xf nightly.tar.gz
git clone --depth 1 git@github.com:MikePopoloski/slang.git

readonly SRC_FOLDER="${BUILDROOT}/slang"
readonly BUILD_FOLDER="${BUILDROOT}/slang-build"

mkdir ${BUILD_FOLDER} || exit 1
cd ${BUILD_FOLDER} || exit 1
cmake -DCMAKE_CXX_COMPILER=afl-clang-fast++ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX="${INSTALLROOT}" -DSLANG_SANITIZERS="address,undefined"  "${SRC_FOLDER}"
make -j "${NCPUS}"
make install

cd "${HOME_USR_BIN}"
ln -s "${INSTALLROOT}/bin/slang" "slang-afl"
