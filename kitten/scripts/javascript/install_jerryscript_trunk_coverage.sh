#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o xtrace
set -o errexit

if [[ "$#" != 1 ]] ; then
  echo "Usage: $0 <install dir>"
  exit 1
fi

readonly HOME_USR_BIN="${HOME}/usr/bin"

readonly INSTALLROOT="$(readlink -f $1)"
echo "Installing to ${INSTALLROOT}"

readonly SRC_FOLDER="${INSTALLROOT}/jerryscript/"
readonly NCPUS="1"

cd "${INSTALLROOT}"

rm -rf "${SRC_FOLDER}" || true # &> /dev/null
git clone --depth 1 --recursive https://github.com/jerryscript-project/jerryscript.git|| exit 1
[[ -d "${SRC_FOLDER}" ]] || exit 1

cd "${SRC_FOLDER}"

readonly FLAGS=(
  "-g -O1 -fsanitize=address,undefined -fno-sanitize-recover=undefined,address --coverage"
)

readonly SHORT_NAMES_FLAGS=(
  "asan_ubsan"
)

readonly NCPU=1

readonly LENGTH="${#FLAGS[@]}"
for (( i=0; i<"${LENGTH}"; i++ )); do
  FLAG="${FLAGS[$i]}"
  SHORT_NAME="${SHORT_NAMES_FLAGS[$i]}"

  BUILD_DIR="${INSTALLROOT}/temp_build_dir_${SHORT_NAME}"
  rm -rf "${BUILD_DIR}" || true
  mkdir -p "${BUILD_DIR}"
  cd "${BUILD_DIR}"

  INSTALL_DIR="${INSTALLROOT}/jerryscript-${SHORT_NAME}"
  cmake -D CMAKE_C_FLAGS="${FLAG}" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_INSTALL_PREFIX:PATH="${INSTALL_DIR}" "${SRC_FOLDER}"
  make -j "${NCPU}"
  make install

  cd "${HOME_USR_BIN}"
  rm -f "jerry-trunk-${SHORT_NAME}"
  ln -s "${INSTALL_DIR}/bin/jerry" "jerry-trunk-${SHORT_NAME}"
done
