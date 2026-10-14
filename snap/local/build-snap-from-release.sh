#!/usr/bin/env bash
# Pack the perses_deploy.jar attached to a GitHub release into a snap. This is
# the only build that may be uploaded to the store: the snap then contains the
# same bytes as the release, and the revision is reproducible from the public
# artifact alone.
#
#   snap/local/build-snap-from-release.sh
#
# The release is v<VERSION>, where VERSION is version/org/perses/version/VERSION.
# snapcraft.yaml reads the snap's version from the same file, so the snap is
# named after the release it packages. Check out the release's commit (or any
# later one with the same VERSION) before running.
#
# Requires: curl, gh, sha256sum, snapcraft. On hosts without LXD, prefix with
# SNAPCRAFT_BUILD_ENVIRONMENT=multipass.
set -euo pipefail
source "$(dirname "$0")/lib.sh"
cd "$ROOT"

echo ">> Looking up $PERSES_JAR in release $RELEASE_TAG"
expected="$(release_jar_digest)"

echo ">> Downloading into snap/local/dist/"
mkdir -p snap/local/dist
rm -f "snap/local/dist/$PERSES_JAR"
curl -fsSL -o "snap/local/dist/$PERSES_JAR" \
  "https://github.com/$PERSES_REPO/releases/download/$RELEASE_TAG/$PERSES_JAR"

actual="$(sha256sum "snap/local/dist/$PERSES_JAR" | awk '{print $1}')"
if [ "$actual" != "$expected" ]; then
  rm -f "snap/local/dist/$PERSES_JAR"
  echo "error: $PERSES_JAR digest $actual does not match the release's $expected." >&2
  exit 1
fi
echo ">> Digest matches the release: sha256:$actual"

echo ">> Packing snap"
snapcraft pack
