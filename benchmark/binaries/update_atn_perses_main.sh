#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if ! [ -e "/tmp/binaries/atn_perses_main_deploy.jar" ]; then
  pushd "${BINARY_DIR}"
  bazel build //atn/src/org/perses/reduction:atn_perses_main_deploy.jar
  mkdir -p /tmp/binaries
  ln -s "${BINARY_DIR}/../../bazel-bin/atn/src/org/perses/reduction/atn_perses_main_deploy.jar" \
       "/tmp/binaries/atn_perses_main_deploy.jar"
  chmod a+X "/tmp/binaries/atn_perses_main_deploy.jar"
  popd
fi

#echo "Compiled on $(date +%Y%m%d_%H%M%S_%Z)" > perses_version.txt
