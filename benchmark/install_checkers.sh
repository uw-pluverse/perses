#!/usr/bin/env bash

# Downloads a Checker Framework release and installs its runtime jars into
# benchmark/benchmark-java/lib/checkerframework-<version>/.
#
# The dists are large (~20 MB each) and there is one per benchmarked checker version, so they are
# fetched on demand here rather than committed to git. setup_env_for_sourcing.sh calls this for each
# version a benchmark needs.
#
# Usage: install_checkers.sh <version>     e.g. install_checkers.sh 3.0.1

set -o errexit
set -o nounset
set -o pipefail

version="${1:?usage: install_checkers.sh <version> (e.g. 3.0.1)}"

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
DEST="${SCRIPT_DIR}/benchmark-java/lib/checkerframework-${version}"

if [ -f "${DEST}/checker.jar" ]; then
  echo "Checker Framework ${version} already installed at ${DEST}"
  exit 0
fi

URL="https://github.com/typetools/checker-framework/releases/download/checker-framework-${version}/checker-framework-${version}.zip"
TMP_ZIP="$(mktemp --suffix=.zip)"
TMP_DIR="$(mktemp -d)"
trap 'rm -rf "${TMP_ZIP}" "${TMP_DIR}"' EXIT

echo "Downloading Checker Framework ${version} from ${URL} ..."
curl -fsSL -o "${TMP_ZIP}" "${URL}"
unzip -q "${TMP_ZIP}" -d "${TMP_DIR}"

DIST="${TMP_DIR}/checker-framework-${version}/checker/dist"
if [ ! -d "${DIST}" ]; then
  echo "Error: ${DIST} not found in the downloaded archive." >&2
  exit 1
fi

mkdir -p "${DEST}"
# Keep only the jars needed to run the checker; the javadoc/source jars are large and unused.
for jar in "${DIST}"/*.jar; do
  case "$(basename "${jar}")" in
    *-javadoc.jar | *-source.jar) continue ;;
  esac
  cp "${jar}" "${DEST}/"
done

echo "Installed Checker Framework ${version} to ${DEST}"
