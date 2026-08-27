#!/usr/bin/env bash
# Build the Perses fat jar and pack it into a snap.
#
#   snap/local/build-snap.sh                        # build + pack
#   SNAPCRAFT_PERSES_VERSION=2.5 snap/local/build-snap.sh
#
# Requires: bazelisk, snapcraft. On hosts without LXD, prefix with
# SNAPCRAFT_BUILD_ENVIRONMENT=multipass.
set -euo pipefail

ROOT="$(bazelisk info workspace)"
cd "$ROOT"

echo ">> Building //src/org/perses:perses_deploy.jar"
bazelisk build //src/org/perses:perses_deploy.jar

echo ">> Staging jar into snap/local/dist/"
mkdir -p snap/local/dist
cp -f bazel-bin/src/org/perses/perses_deploy.jar snap/local/dist/perses_deploy.jar

echo ">> Packing snap"
snapcraft pack

echo ">> Done. Install locally with:"
echo "   sudo snap install --classic --dangerous ./perses_*.snap"
