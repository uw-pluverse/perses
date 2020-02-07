#!/usr/bin/env bash

set -o pipefail
set -o errexit
set -o nounset
set -o xtrace

readonly DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
bazel build //src/org/perses:perses_deploy.jar
readonly PERSES_JAR="${DIR}/../bazel-bin/src/org/perses/perses_deploy.jar"

java -jar "${PERSES_JAR}" "${@}"
