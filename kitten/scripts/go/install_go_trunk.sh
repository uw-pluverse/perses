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

readonly SRC_FOLDER="${BUILDROOT}/go/"
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
git clone --depth 1 https://go.googlesource.com/go || exit 1

[[ -d "${SRC_FOLDER}" ]] || exit 1

cd "${SRC_FOLDER}/src"
export GOROOT_FINAL="${INSTALLROOT}"
./all.bash || exit 1

rm -rf "${INSTALLROOT}/*"
cp -rf "${SRC_FOLDER}" "${INSTALLROOT}"

cd "${HOME_USR_BIN}"
ln -s "${INSTALLROOT}/go/bin/go" "go-trunk"
ln -s "${INSTALLROOT}/go/bin/gofmt" "gofmt-trunk"
./go-trunk version

