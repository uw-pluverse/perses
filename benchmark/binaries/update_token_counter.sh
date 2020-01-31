#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if ! [ -e "/tmp/binaries/token_counter_deploy.jar" ]; then
  pushd "${BINARY_DIR}"
  bazel build //src/org/perses:token_counter_deploy.jar
  mkdir -p /tmp/binaries
  ln -s "${BINARY_DIR}/../../bazel-bin/src/org/perses/token_counter_deploy.jar" \
       "/tmp/binaries/token_counter_deploy.jar"
  chmod a+x "/tmp/binaries/token_counter_deploy.jar"
  popd
fi
