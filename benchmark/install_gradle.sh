#!/usr/bin/env bash

# Downloads Gradle (used to run the NullAway benchmarks, which apply NullAway as an Error Prone
# plugin via the net.ltgt.errorprone Gradle plugin) into benchmark/binaries/gradle.
#
# Like the JDK installers, the distribution is fetched on demand rather than committed.

set -o errexit
set -o nounset
set -o pipefail

GRADLE_VERSION="8.13"
URL="https://services.gradle.org/distributions/gradle-${GRADLE_VERSION}-bin.zip"

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
BINARIES_DIR="$SCRIPT_DIR/binaries"
GRADLE_DEST_DIR="$BINARIES_DIR/gradle"
GRADLE_BINARY="$GRADLE_DEST_DIR/bin/gradle"

if [ -x "$GRADLE_BINARY" ]; then
  echo "Gradle already installed at $GRADLE_DEST_DIR"
  exit 0
fi

TMP_ZIP="$(mktemp --suffix=.zip)"
TMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TMP_ZIP" "$TMP_DIR"' EXIT

echo "Downloading Gradle ${GRADLE_VERSION} from ${URL} ..."
curl -fsSL -o "$TMP_ZIP" "$URL"
unzip -q "$TMP_ZIP" -d "$TMP_DIR"
rm -rf "$GRADLE_DEST_DIR"
mkdir -p "$GRADLE_DEST_DIR"
mv "$TMP_DIR/gradle-${GRADLE_VERSION}"/* "$GRADLE_DEST_DIR/"

if [ -x "$GRADLE_BINARY" ]; then
  echo "Gradle ${GRADLE_VERSION} installed successfully at $GRADLE_DEST_DIR"
else
  echo "Error: Failed to install Gradle." >&2
  exit 1
fi
