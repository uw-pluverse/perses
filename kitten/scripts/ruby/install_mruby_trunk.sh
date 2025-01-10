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
trap "rm -rf ${BUILDROOT}" EXIT

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

git clone https://github.com/mruby/mruby.git

readonly SRC_FOLDER="${BUILDROOT}/mruby"

cd "${SRC_FOLDER}"
rake

cd "${HOME_USR_BIN}"
ln -s "${INSTALLROOT}/mruby/bin/mruby" "mruby-trunk"
./mruby-trunk -v
