#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if ! [ -e "/tmp/binaries/perses_deploy.jar" ]; then
  pushd "${BINARY_DIR}"
  bazel build //src/org/perses:perses_deploy.jar
  mkdir -p /tmp/binaries
  ln -s "${BINARY_DIR}/../../bazel-bin/src/org/perses/perses_deploy.jar" \
       "/tmp/binaries/perses_deploy.jar"
  chmod a+X "/tmp/binaries/perses_deploy.jar"
  popd
fi

#echo "Compiled on $(date +%Y%m%d_%H%M%S_%Z)" > perses_version.txt
