# Shared by the snap build, check and upload scripts. Source it; do not run it.

readonly PERSES_REPO="uw-pluverse/perses"
readonly PERSES_JAR="perses_deploy.jar"

ROOT="$(git -C "$(dirname "${BASH_SOURCE[0]}")" rev-parse --show-toplevel)"
SNAP_NAME="$(awk '/^name:/{print $2; exit}' "$ROOT/snap/snapcraft.yaml")"
VERSION="$(tr -d '[:space:]' < "$ROOT/version/org/perses/version/VERSION")"
RELEASE_TAG="v$VERSION"
# The file `snapcraft pack` writes for this VERSION on this host.
SNAP_FILE="$ROOT/${SNAP_NAME}_${VERSION}_$(dpkg --print-architecture).snap"

# Prints the hex sha256 GitHub publishes for the release's jar, or fails.
release_jar_digest() {
  local digest
  digest="$(gh api "repos/$PERSES_REPO/releases/tags/$RELEASE_TAG" \
    --jq ".assets[] | select(.name == \"$PERSES_JAR\") | .digest")" || {
    echo "error: release $RELEASE_TAG not found in $PERSES_REPO." >&2
    return 1
  }
  if [[ "$digest" != sha256:* ]]; then
    echo "error: release $RELEASE_TAG has no $PERSES_JAR with a sha256 digest (got '$digest')." >&2
    return 1
  fi
  echo "${digest#sha256:}"
}
