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

readonly SRC_FOLDER="${BUILDROOT}/solidity/"
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
git clone --depth 1 --recursive https://github.com/ethereum/solidity.git || exit 1
[[ -d "${SRC_FOLDER}" ]] || exit 1

cd "${BUILDROOT}"

readonly FLAGS=(
  "-g -O1 -fsanitize=address,undefined -fno-sanitize-recover=undefined,address"
)
readonly SHORT_NAMES_FLAGS=(
  "asan_ubsan"
)

readonly NCPU=1

readonly LENGTH="${#FLAGS[@]}"
for (( i=0; i<"${LENGTH}"; i++ )); do
  FLAG="${FLAGS[$i]}"
  SHORT_NAME="${SHORT_NAMES_FLAGS[$i]}"

  BUILD_DIR="${BUILDROOT}/temp_build_dir_${SHORT_NAME}"
  rm -rf "${BUILD_DIR}" || true
  mkdir -p "${BUILD_DIR}"
  cd "${BUILD_DIR}"

  INSTALL_DIR="${INSTALLROOT}/solidity-${SHORT_NAME}"

  export CC=clang CXX=clang++
  cmake -E env CXXFLAGS="  ${FLAG} " cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX:PATH="${INSTALL_DIR}" "${SRC_FOLDER}"
  make -j "${NCPU}"
  make install

  cd "${HOME_USR_BIN}"
  ln -s "${INSTALL_DIR}/bin/solc" "solc-trunk-${SHORT_NAME}"
done
