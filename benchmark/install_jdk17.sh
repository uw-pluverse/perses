#!/usr/bin/env bash

# This script downloads and installs Eclipse Temurin JDK 17.0.9 into the benchmark/binaries
# directory. JDK 17.0.9 is needed by the javac (jdk-*) benchmarks: the bug is in that specific
# javac build, fixed in later releases.

set -o errexit
set -o nounset
set -o pipefail

JDK_VERSION="17.0.9+9"
URL="https://github.com/adoptium/temurin17-binaries/releases/download/jdk-17.0.9%2B9/OpenJDK17U-jdk_x64_linux_hotspot_17.0.9_9.tar.gz"

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
BINARIES_DIR="$SCRIPT_DIR/binaries"
JDK_DEST_DIR="$BINARIES_DIR/jdk17"
JAVA_BINARY="$JDK_DEST_DIR/bin/java"

if [ -f "$JAVA_BINARY" ]; then
    echo "JDK 17 is already installed at $JDK_DEST_DIR"
    exit 0
fi

echo "Installing JDK $JDK_VERSION..."
mkdir --parents "$BINARIES_DIR"
TEMP_TARBALL="$(mktemp --suffix=.tar.gz)"
TEMP_EXTRACT_DIR="$(mktemp -d)"
trap 'rm -rf "$TEMP_TARBALL" "$TEMP_EXTRACT_DIR"' EXIT

echo "Downloading JDK $JDK_VERSION from $URL..."
curl -fsSL -o "$TEMP_TARBALL" "$URL"
tar -xzf "$TEMP_TARBALL" -C "$TEMP_EXTRACT_DIR"

extracted_subdir=$(find "$TEMP_EXTRACT_DIR" -maxdepth 1 -mindepth 1 -type d)
rm --recursive --force "$JDK_DEST_DIR"
mkdir -p "$JDK_DEST_DIR"
mv "$extracted_subdir"/* "$JDK_DEST_DIR/"

if [ -f "$JAVA_BINARY" ]; then
    echo "JDK 17 installed successfully at $JDK_DEST_DIR"
    "$JAVA_BINARY" -version 2>&1 | head -1
else
    echo "Error: Failed to install JDK 17." >&2
    exit 1
fi
