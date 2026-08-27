#!/usr/bin/env bash
#
# Build the perses build-and-test image, the one scripts/presubmit.sh runs in.
#
#   ./build_image.sh                 # builds cnsun/perses:dev_v1
#   ./build_image.sh -t my-tag       # builds my-tag
#
# The build installs the Ubuntu tool chain, clang 18 from apt.llvm.org, a pinned rust toolchain,
# wasmedge, and bazelisk with bazel pre-warmed (~1.5 GB of downloads, ~5 minutes cold) for a
# ~3.5 GB image. Each payload is its own layer, so a rerun after a network hiccup resumes.
set -o errexit
set -o nounset
set -o pipefail

readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly WORKSPACE="$(git -C "${SCRIPT_DIR}" rev-parse --show-toplevel)"
readonly DEFAULT_TAG="cnsun/perses:dev_v1"
# The bazel release to pre-warm into the image. Read from the workspace so the image never lags
# behind a .bazelversion bump (bazelisk would otherwise download the new one on every run).
readonly BAZEL_VERSION="$(cat "${WORKSPACE}/.bazelversion")"

tag="${DEFAULT_TAG}"
while [[ $# -gt 0 ]]; do
  case "$1" in
    -t | --tag)
      tag="$2"
      shift 2
      ;;
    -h | --help)
      sed -n '2,11p' "${BASH_SOURCE[0]}"
      exit 0
      ;;
    *)
      echo "unexpected argument: $1" >&2
      exit 2
      ;;
  esac
done

docker build --tag "${tag}" \
  --build-arg "BAZEL_VERSION=${BAZEL_VERSION}" \
  "${SCRIPT_DIR}"

echo
echo "Built ${tag}. Verify the tool chain with:"
echo "  ./docker/dev/test_image.sh -t ${tag}"
echo "Then run the presubmit inside it with:"
echo "  ./docker/dev/run.sh -t ${tag}"
