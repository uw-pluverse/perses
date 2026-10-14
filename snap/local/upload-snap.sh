#!/usr/bin/env bash
# Upload the snap that build-and-verify-snap.sh produced to the Snap Store.
#
#   snap/local/upload-snap.sh [path/to/perses_*.snap]
#
# Refuses unless the snap is byte-identical to the one that passed every check
# (its <snap>.verified marker) and its jar is the GitHub release's jar.
#
# Uploads only; it never releases. A classic revision waits in manual review
# until the store grants classic, and a release attempt would fail there. After
# the upload, release with the command this script prints.
set -euo pipefail
source "$(dirname "$0")/lib.sh"

snap_file="${1:-$SNAP_FILE}"
[ -f "$snap_file" ] || { echo "error: $snap_file not found; run build-and-verify-snap.sh." >&2; exit 1; }

marker="$snap_file.verified"
actual="$(sha256sum "$snap_file" | awk '{print $1}')"
if [ ! -f "$marker" ] || [ "$(cat "$marker")" != "$actual" ]; then
  echo "error: $snap_file has not passed build-and-verify-snap.sh (or changed since)." >&2
  exit 1
fi

echo ">> Checking the bundled jar against release $RELEASE_TAG"
expected="$(release_jar_digest)"
bundled="$(unsquashfs -cat "$snap_file" "jar/$PERSES_JAR" | sha256sum | awk '{print $1}')"
if [ "$bundled" != "$expected" ]; then
  echo "error: the snap's jar ($bundled) is not the $RELEASE_TAG release jar ($expected)." >&2
  exit 1
fi

snapcraft whoami >/dev/null 2>&1 || {
  echo "error: not logged in to the store; run 'snapcraft login' in a terminal." >&2
  exit 1
}

echo ">> Uploading $snap_file"
snapcraft upload "$snap_file"
echo ">> Once the revision is approved, release it with:"
echo "   snapcraft release $SNAP_NAME <revision> stable"
