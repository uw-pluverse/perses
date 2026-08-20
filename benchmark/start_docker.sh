#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

readonly BASENAME=$(basename "${0}")
readonly DIR=$(dirname "${0}")
if [[ -n "${DIR}" ]] && [[ "${DIR}" != "." ]]; then
  echo "This script has to be called within its parent directory, namely run ./${BASENAME} in '${DIR}'" 1>&2
  exit 1
fi

readonly WORKSPACE=$(realpath "../")
if [[ ! -f "${WORKSPACE}/WORKSPACE" ]]; then
  echo "Ths directory ${WORKSPACE} is not a bazel workspace."
  exit 1
fi

docker pull cnsun/perses:perses_part_54_name_clang_trunk

readonly PERSES_ROOT_IN_DOCKER="/tmp/perses"

readonly USER_ID=$(id --user)
# Do not allow running as root. If the current user is root, then the docker image does not work.
if [[ "${USER_ID}" -eq 0 ]]; then
  echo "ERROR: The docker image does not work if the current user is root."
  exit 1
fi
readonly USER_NAME=$(id --user --name)
readonly GROUP_ID=$(id --group)
readonly GROUP_NAME=$(id --group --name)

readonly UPDATE_BAZEL_SCRIPT="update_bazel.sh"
cat > "${UPDATE_BAZEL_SCRIPT}" <<- EOF
#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

wget https://github.com/bazelbuild/bazelisk/releases/download/v1.11.0/bazelisk-linux-amd64
chmod +x bazelisk-linux-amd64
# The bazel binary is bazelisk
sudo mv bazelisk-linux-amd64 /usr/local/bin/bazel
sudo ln -s /usr/local/bin/bazel /usr/local/bin/bazelisk

EOF
chmod +x "${UPDATE_BAZEL_SCRIPT}"

readonly INIT_DOCKER_SCRIPT="init_docker.sh"
cat > "${INIT_DOCKER_SCRIPT}" <<- EOF
#!/usr/bin/env bash
  
set -o nounset
set -o pipefail

getent group $GROUP_ID > /dev/null
if [ \$? -ne 0 ]; then
  sudo groupadd --gid ${GROUP_ID} ${GROUP_NAME}
fi

getent passwd $USER_ID > /dev/null
if [ \$? -ne 0 ]; then
  sudo useradd --shell "/bin/bash" --create-home --uid ${USER_ID} --gid ${GROUP_ID} --groups sudo ${USER_NAME}
fi

echo "Change password for \$(id -nu $USER_ID) in docker"
sudo passwd \$(id -nu $USER_ID)

sudo --user=\$(id -nu $USER_ID) ./${UPDATE_BAZEL_SCRIPT}
sudo --user=\$(id -nu $USER_ID) ./install_clangd.sh
sudo ln --symbolic --force "${PERSES_ROOT_IN_DOCKER}/benchmark/binaries/clangd-18/bin/clangd" /usr/local/bin/clangd
sudo ln --symbolic --force "${PERSES_ROOT_IN_DOCKER}/benchmark/binaries/clangd-18/bin/clangd" /usr/local/bin/clangd-18

echo "Switching to user \$(id -nu $USER_ID)"
su \$(id -nu $USER_ID)
EOF
chmod +x "${INIT_DOCKER_SCRIPT}"

trap "rm ${INIT_DOCKER_SCRIPT} ${UPDATE_BAZEL_SCRIPT}" EXIT

# --cap-add is to enable LeakSanitizer
#   See https://github.com/google/sanitizers/issues/764
docker container run \
  --volume "${WORKSPACE}:${PERSES_ROOT_IN_DOCKER}" \
  --cap-add SYS_PTRACE \
  --interactive \
  --tty cnsun/perses:perses_part_54_name_clang_trunk
