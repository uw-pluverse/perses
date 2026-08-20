#!/usr/bin/env bash

# Enable safety flags with long names
set -o errexit
set -o nounset
set -o pipefail

# Configuration
MAJOR_VERSION="18"
VERSION="${MAJOR_VERSION}.1.3"

# Get the directory where this script is located
# shellcheck disable=SC2164
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
BINARIES_DIR="$SCRIPT_DIR/binaries"
CLANGD_DEST_DIR="$BINARIES_DIR/clangd-$MAJOR_VERSION"
CLANGD_BINARY="$CLANGD_DEST_DIR/bin/clangd"

# Function to verify clangd version
verify_version() {
    local binary=$1
    echo "Verifying clangd version..."
    local version_output=$("$binary" --version)
    echo "$version_output"
    if [[ "$version_output" == *"clangd version $MAJOR_VERSION"* ]]; then
        echo "Version verification successful: major version is $MAJOR_VERSION."
    else
        echo "Error: Version verification failed. Expected major version $MAJOR_VERSION."
        exit 1
    fi
}

if [ -f "$CLANGD_BINARY" ]; then
    echo "clangd is already installed at $CLANGD_BINARY"
    verify_version "$CLANGD_BINARY"
    exit 0
fi

echo "Installing clangd $VERSION..."

# Create binaries directory if it doesn't exist
mkdir --parents "$BINARIES_DIR"

# Temporary download and unzip
TEMP_ZIP="$BINARIES_DIR/clangd-linux-$VERSION.zip"
URL="https://github.com/clangd/clangd/releases/download/$VERSION/clangd-linux-$VERSION.zip"

# Setup trap for cleanup
cleanup() {
    if [ -f "$TEMP_ZIP" ]; then
        echo "Cleaning up temporary files..."
        rm --force "$TEMP_ZIP"
    fi
}
trap cleanup EXIT

echo "Downloading clangd $VERSION from $URL..."
rm --force "$TEMP_ZIP" # Ensure any existing partial or old zip is removed
wget --output-document="$TEMP_ZIP" "$URL"

echo "Unzipping clangd..."
# The zip contains a folder named clangd_VERSION
# We unzip into the binaries directory
# Note: unzip does not support many long flags; using -q and -d
unzip -q "$TEMP_ZIP" -d "$BINARIES_DIR"

# Rename to the desired directory name clangd-MAJOR_VERSION as requested
extracted_dir="$BINARIES_DIR/clangd_$VERSION"
if [ -d "$extracted_dir" ]; then
    rm --recursive --force "$CLANGD_DEST_DIR"
    mv "$extracted_dir" "$CLANGD_DEST_DIR"
fi

if [ -f "$CLANGD_BINARY" ]; then
    echo "clangd installed successfully at $CLANGD_BINARY"
    verify_version "$CLANGD_BINARY"
else
    echo "Error: Failed to install clangd."
    exit 1
fi
