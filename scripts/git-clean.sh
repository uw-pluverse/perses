#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

git clean -d --interactive -x
