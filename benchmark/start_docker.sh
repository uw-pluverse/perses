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

docker pull cnsun/perses:perses_part_54_name_clang_trunk

readonly PERSES_ROOT_IN_DOCKER="/tmp/perses"

readonly USER_ID=$(id --user)
readonly USER_NAME=$(id --user --name)
readonly GROUP_ID=$(id --group)
readonly GROUP_NAME=$(id --group --name)

readonly UPDATE_BAZEL_SCRIPT="update_bazel.sh"
cat > "${UPDATE_BAZEL_SCRIPT}" <<-EOF
#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

#sudo apt install --yes curl gnupg
#curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
#sudo mv bazel.gpg /etc/apt/trusted.gpg.d/
#echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
#
#sudo apt update && sudo apt install --yes bazel
#
#sudo mv /usr/local/bin/bazel /usr/local/bin/bazel.bak

wget https://github.com/bazelbuild/bazelisk/releases/download/v1.11.0/bazelisk-linux-amd64
chmod +x bazelisk-linux-amd64
sudo mv bazelisk-linux-amd64 /usr/local/bin/bazel

EOF
chmod +x "${UPDATE_BAZEL_SCRIPT}"

readonly INIT_DOCKER_SCRIPT="init_docker.sh"
cat > "${INIT_DOCKER_SCRIPT}" <<-EOF
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
