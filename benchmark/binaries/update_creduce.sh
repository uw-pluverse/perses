#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

if ! type "creduce" > /dev/null; then
  sudo apt-get install -y creduce
fi

#echo $(creduce --version) > creduce_version.txt
