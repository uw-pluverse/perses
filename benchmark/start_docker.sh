#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

readonly BASENAME=$(basename "${0}")
readonly DIR=$(dirname "${0}")
if [[ -n "${DIR}" ]] && [[ "${DIR}" != "." ]]
then
  echo "This script has to be called within its parent directory, namely run ./${BASENAME} in '${DIR}'" 1>&2
  exit 1
fi

readonly WORKSPACE=$(realpath "../")
if [[ ! -f "${WORKSPACE}/WORKSPACE" ]]
then
  echo "Ths directory ${WORKSPACE} is not a bazel workspace."
  exit 1
fi

rm ${WORKSPACE}/bazel-* || true

readonly DOCKER_GID=1000 # The gid of coq is 1000.
readonly DOCKER_GNAME="perses_docker_group"

sudo chown -R ":${DOCKER_GID}" "${WORKSPACE}" 
sudo chmod 775 "${WORKSPACE}" 
sudo chmod g+s "${WORKSPACE}"


docker pull cnsun/perses:perses_part_54_name_clang_trunk

# --cap-add is to enable LeakSanitizer
#   See https://github.com/google/sanitizers/issues/764

docker container run \
  --volume "${WORKSPACE}:/tmp/perses" \
	--cap-add SYS_PTRACE \
	--interactive \
	--tty cnsun/perses:perses_part_54_name_clang_trunk 
# 
# bash -c "sudo addgroup --gid ${DOCKER_GID} ${DOCKER_GNAME} ; sudo usermod -a -G ${DOCKER_GNAME} coq; /bin/bash"
