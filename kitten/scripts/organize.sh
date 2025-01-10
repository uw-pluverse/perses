#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

bazelisk build //kitten/src/org/perses/fuzzer/organizer:main_deploy.jar

java -jar bazel-bin/kitten/src/org/perses/fuzzer/organizer/main_deploy.jar "$@"