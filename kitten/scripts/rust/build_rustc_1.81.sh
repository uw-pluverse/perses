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

readonly SRC_FOLDER="${BUILDROOT}/rust/"

function cleanup() {
  rm -rf "${BUILDROOT}" &> /dev/null || true
}
trap cleanup EXIT

readonly INSTALLROOT="$(readlink -f $1)"
echo "Installing to ${INSTALLROOT}"

cd "${BUILDROOT}"

rm -rf "${SRC_FOLDER}" || true # &> /dev/null
git clone --depth 1 -b 1.58.1 https://github.com/rust-lang/rust|| exit 1
[[ -d "${SRC_FOLDER}" ]] || exit 1

cd "${SRC_FOLDER}"

cp config.toml.example config.toml

sed -i "s+#prefix = \"/usr/local\"+prefix = \"${INSTALLROOT}\"+" config.toml

sed -i "s/#ninja = true/ninja = false/" config.toml

./x.py build && ./x.py install

