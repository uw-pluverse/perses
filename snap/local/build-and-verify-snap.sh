#!/usr/bin/env bash
# Build the store snap from the GitHub release and run every check on it:
#
#   snap/local/build-and-verify-snap.sh
#
#   1. build-snap-from-release.sh  packs the release jar for v<VERSION>
#   2. verify-snap.sh              real `snap install` + functional checks (sudo)
#   3. verify-distros.sh           ELF audit + runs in each distro container
#
# Stops at the first failure. On success it writes <snap>.verified holding the
# snap's sha256, which upload-snap.sh requires, so only a snap that passed all
# three steps can be uploaded.
#
# Picks the Multipass build backend when SNAPCRAFT_BUILD_ENVIRONMENT is unset
# and LXD is absent.
set -euo pipefail
source "$(dirname "$0")/lib.sh"

if [ -z "${SNAPCRAFT_BUILD_ENVIRONMENT:-}" ] && ! command -v lxc >/dev/null 2>&1 \
  && command -v multipass >/dev/null 2>&1; then
  export SNAPCRAFT_BUILD_ENVIRONMENT=multipass
fi

# Prompt for the password now rather than after a several-minute build.
sudo -v

rm -f "$SNAP_FILE" "$SNAP_FILE.verified"

echo "== 1/3 Build from release $RELEASE_TAG"
"$ROOT/snap/local/build-snap-from-release.sh"
[ -f "$SNAP_FILE" ] || { echo "error: expected $SNAP_FILE after the build." >&2; exit 1; }

echo "== 2/3 Install and smoke-test on this host"
"$ROOT/snap/local/verify-snap.sh" "$SNAP_FILE"

echo "== 3/3 Cross-distro check"
"$ROOT/snap/local/verify-distros.sh" "$SNAP_FILE"

sha256sum "$SNAP_FILE" | awk '{print $1}' > "$SNAP_FILE.verified"
echo "== All checks passed: $SNAP_FILE"
echo "   Upload with: snap/local/upload-snap.sh"
