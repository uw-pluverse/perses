#!/usr/bin/env bash

if [[ -n "${CARGO_HOME}" ]] ; then
  echo "Does not support CARGO_HOME yet."
  exit 1
fi

set -o pipefail
set -o nounset
set -o errexit

function install_rustup() {
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- \
    --default-toolchain nightly \
    --no-modify-path \
    -y # ignore all ignorable checks.
}

readonly BIN="${HOME}/.cargo/bin"
readonly RUSTUP="${BIN}/rustup"

if ! [[ -f "${RUSTUP}" ]] ; then
  echo "Installing rustup, as it does not exist."
  install_rustup || exit 1
fi

"${RUSTUP}" update

xargs "${RUSTUP}" install < "rust_versions.txt"

"${RUSTUP}" update