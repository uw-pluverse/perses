#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

bazel run //:buildifier