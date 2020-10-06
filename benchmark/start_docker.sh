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
readonly GROUP_ID=$(id --group)
readonly FIX_PERMISSIONS_SCRIPT="fix_file_permissions.sh"
cat > "${FIX_PERMISSIONS_SCRIPT}" <<-EOF
#!/usr/bin/env bash 
set -o nounset
set -o errexit
set -o pipefail
sudo chown "${USER_ID}:${GROUP_ID}" "${PERSES_ROOT_IN_DOCKER}" -R
EOF
chmod +x "${FIX_PERMISSIONS_SCRIPT}"

readonly UPDATE_BAZEL_SCRIPT="update_bazel.sh"
cat > "${UPDATE_BAZEL_SCRIPT}" <<-EOF
#!/usr/bin/env bash
  
set -o nounset
set -o pipefail
set -o errexit

sudo apt install --yes curl gnupg
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
sudo mv bazel.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list

sudo apt update && sudo apt install --yes bazel

sudo mv /usr/local/bin/bazel /usr/local/bin/bazel.bak
EOF
chmod +x "${UPDATE_BAZEL_SCRIPT}"

trap "rm ${FIX_PERMISSIONS_SCRIPT} ${UPDATE_BAZEL_SCRIPT}" EXIT

# --cap-add is to enable LeakSanitizer
#   See https://github.com/google/sanitizers/issues/764
docker container run \
        --volume "${WORKSPACE}:${PERSES_ROOT_IN_DOCKER}" \
	--cap-add SYS_PTRACE \
	--interactive \
	--tty cnsun/perses:perses_part_54_name_clang_trunk 

