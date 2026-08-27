#!/usr/bin/env bash
#
# Verify the dev image really is the environment presubmit expects.
#
#   ./docker/dev/test_image.sh                 # checks cnsun/perses:dev_v1
#   ./docker/dev/test_image.sh -t my-tag
#   ./docker/dev/test_image.sh --versions-only # skip the check_prerequisite.sh pass
#
# Two passes:
#   1. check_versions.sh, in a bare container: the pinned versions the goldens depend on.
#   2. scripts/check_prerequisite.sh itself, against this checkout. It owns the authoritative tool
#      list, so it is run rather than duplicated. NOTE: on a fresh checkout this downloads and
#      builds benchmark_v2/binaries/{jdk21,clangd-18,jdtls-1.33.0,java-language-server}, which
#      takes several minutes; --versions-only skips it.
set -o errexit
set -o nounset
set -o pipefail

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly WORKSPACE="$(git -C "${SCRIPT_DIR}" rev-parse --show-toplevel)"
readonly DEFAULT_TAG="cnsun/perses:dev_v1"

tag="${DEFAULT_TAG}"
versions_only=0
while [[ $# -gt 0 ]]; do
  case "$1" in
    -t | --tag)
      tag="$2"
      shift 2
      ;;
    --versions-only)
      versions_only=1
      shift
      ;;
    -h | --help)
      sed -n '2,17p' "${BASH_SOURCE[0]}"
      exit 0
      ;;
    *)
      echo "unexpected argument: $1" >&2
      exit 2
      ;;
  esac
done

echo "== checking pinned tool versions in ${tag} =="
docker run --rm \
  --env "EXPECTED_BAZEL_VERSION=$(cat "${WORKSPACE}/.bazelversion")" \
  --volume "${SCRIPT_DIR}/check_versions.sh:/check_versions.sh:ro" \
  "${tag}" bash /check_versions.sh

if [[ "${versions_only}" -eq 1 ]]; then
  echo
  echo "Skipping scripts/check_prerequisite.sh (--versions-only)."
  exit 0
fi

echo
echo "== running scripts/check_prerequisite.sh inside ${tag} =="
"${SCRIPT_DIR}/run.sh" -t "${tag}" --exec ./scripts/check_prerequisite.sh

echo
echo "${tag} is ready. Run the presubmit with:"
echo "  ./docker/dev/run.sh -t ${tag}"
