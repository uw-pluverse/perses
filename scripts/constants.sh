# This file is intended to be sourced by other script files.

set -o nounset
set -o pipefail
set -o errexit

readonly WORKSPACE_ROOT=$(bazel info | grep "workspace:" | awk '{ print $2 }')
if [[ ! -e "${WORKSPACE_ROOT}/WORKSPACE" ]] ; then
  echo "ERROR: The computed workspace root ${WORKSPACE_ROOT} does not have a WORKSPACE file."
  exit 1
fi

cd "${WORKSPACE_ROOT}"

BAZEL_DIRS=(
  "antlropt"
  "copyright"
  "src"
  "test"
  "version"
)

readonly SUBMODULE_BAZEL_DIRS=(
  "antlrrdc"
  "arabica"
  "atn"
  "buildopt"
  "global_cache/src"
  "global_cache/test"
  "latra"
  "ppr"
  "fision/src"
  "fision/test"
  "perses-fuzzer/src"
  "perses-fuzzer/test"
  "pigen/ast"
  "pigen/chaoty"
  "weighted-dd"
)
for submodule in "${SUBMODULE_BAZEL_DIRS[@]}" ; do
  [[ -z "$(find "${submodule}" -name BUILD)" ]] && continue
  BAZEL_DIRS+=("${submodule}")
done

ABS_BAZEL_DIRS=()
ABS_BAZEL_DIRS_STRING=""
for dir in "${BAZEL_DIRS[@]}" ; do
  abs_path="${WORKSPACE_ROOT}/${dir}"
  ABS_BAZEL_DIRS+=("${abs_path}")
  ABS_BAZEL_DIRS_STRING="${ABS_BAZEL_DIRS_STRING} ${abs_path}"
done

ALL_BAZEL_BUILD_TARGETS=()
ALL_BAZEL_BUILD_TARGETS_STRING=""
for dir in "${BAZEL_DIRS[@]}" ; do
  build_target="//${dir}/..."
  ALL_BAZEL_BUILD_TARGETS+=("${build_target}")
  ALL_BAZEL_BUILD_TARGETS_STRING="${ALL_BAZEL_BUILD_TARGETS_STRING} ${build_target}"
done
