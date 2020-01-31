#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

if ! type "chisel" > /dev/null; then
  pushd /tmp
  sudo apt-get update
  sudo apt-get install -y software-properties-common
  sudo apt-get install -y gnupg2
  wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add
  sudo apt-add-repository "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-8 main" && sudo apt-get update
  sudo apt-get install -y clang-8 libclang-8-dev llvm-8-dev cmake
  wget http://archive.ubuntu.com/ubuntu/pool/universe/s/spdlog/libspdlog-dev_1.3.1-1_amd64.deb
  sudo dpkg -i libspdlog-dev_1.3.1-1_amd64.deb
  sudo apt-get install -y libmlpack-dev
  #sudo mv /usr/bin/clang /usr/bin/clang-backup
  sudo ln -sf /usr/bin/clang-8 /usr/bin/clang
  #sudo mv /usr/bin/llvm-config /usr/bin/llvm-config-backup
  sudo ln -sf /usr/bin/llvm-config-8 /usr/bin/llvm-config

  git clone https://github.com/aspire-project/chisel.git
  cd chisel
  mkdir build
  cd build
  cmake -DCMAKE_CXX_COMPILER=clang-8 ..
  make -j
  sudo cp ./bin/chisel /usr/bin

  #sudo mv /usr/bin/clang-backup /usr/bin/clang
  #sudo mv /usr/bin/llvm-config-backup /usr/bin/llvm-config
  popd
fi
