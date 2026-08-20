#/usr/bin/env bash

set -o pipefail

if [[ "$#" != 2 ]] ; then
  echo "$0 <.c file> <.wat file>"
  exit 1
fi
readonly C_FILE="$1"
readonly WAT_FILE="$2"
readonly CURRENT_DIR=$(pwd)
readonly SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)

cd "${SCRIPT_DIR}"
readonly GIT_DIR="emsdk"

if [[ ! -e "${GIT_DIR}" ]] ; then
  git clone https://github.com/emscripten-core/emsdk.git
fi

cd "${GIT_DIR}"
git pull

readonly VERSION="4.0.22"
./emsdk install "${VERSION}"
./emsdk activate "${VERSION}"

export PATH="${PATH}:${SCRIPT_DIR}/${GIT_DIR}"
export PATH="${PATH}:${SCRIPT_DIR}/${GIT_DIR}/upstream/emscripten"

cd "${CURRENT_DIR}"
readonly WASM_FILE="${C_FILE}.wasm"
emcc "${C_FILE}" -o "${WASM_FILE}" -s STANDALONE_WASM=1

wasm2wat "${WASM_FILE}" -o "${WAT_FILE}"






