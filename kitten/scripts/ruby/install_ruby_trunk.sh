#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o xtrace
set -o errexit

if [[ "$#" != 1 ]] ; then
  echo "Usage: $0 <install dir>"
  exit 1
fi

readonly TOOLS=("gcc"
    "autoconf"
    "bison"
    "gperf"
    "ruby")

missing=""
for tool in "${TOOLS[@]}" ; do
  if ! command -v "${tool}" &> /dev/null ; then
    missing="${missing} ${tool}"
  fi
done

if [[ "${missing}" != "" ]] ; then
  echo "The following tools are missing: ${missing}"
fi

if apt list --installed | grep "libyaml-dev" ; then
  echo "libyaml-dev is installed"
else
  echo "You need to manually install libyaml-dev"
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
git clone --depth 1 https://github.com/ruby/ruby.git

readonly SRC_FOLDER="${BUILDROOT}/ruby"

cd "${SRC_FOLDER}"
./autogen.sh
mkdir build && cd build # its good practice to build outside of source dir
../configure --prefix="${INSTALLROOT}/ruby"
make -j 30
make install

cd "${HOME_USR_BIN}"
ln -s "${INSTALLROOT}/ruby/bin/ruby" "ruby-trunk"
./ruby-trunk -v
