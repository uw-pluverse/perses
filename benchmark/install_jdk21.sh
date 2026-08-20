#!/usr/bin/env bash

# This script downloads and installs Eclipse Temurin JDK 21
# into the benchmark/binaries directory.

# Enable safety flags with long names
set -o errexit
set -o nounset
set -o pipefail

# Configuration
JDK_VERSION="21.0.2+13"
# URL for Linux x64
URL="https://github.com/adoptium/temurin21-binaries/releases/download/jdk-21.0.2%2B13/OpenJDK21U-jdk_x64_linux_hotspot_21.0.2_13.tar.gz"

# Get the directory where this script is located
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
BINARIES_DIR="$SCRIPT_DIR/binaries"
JDK_DEST_DIR="$BINARIES_DIR/jdk21"
JAVA_BINARY="$JDK_DEST_DIR/bin/java"

# Function to verify java version
verify_installation() {
    local binary=$1
    echo "Verifying JDK 21 installation..."
    if [ ! -f "$binary" ]; then
        echo "Error: java binary not found at $binary"
        exit 1
    fi
    local version_output=$("$binary" -version 2>&1)
    echo "$version_output"
    if [[ "$version_output" == *"openjdk version \"21.0.2\""* ]]; then
        echo "Version verification successful: JDK 21 ($JDK_VERSION) is installed."
    else
        echo "Error: Version verification failed or version mismatch."
        exit 1
    fi
}

if [ -f "$JAVA_BINARY" ]; then
    echo "JDK 21 is already installed at $JDK_DEST_DIR"
    verify_installation "$JAVA_BINARY"
    exit 0
fi

echo "Installing JDK $JDK_VERSION..."

# Create binaries directory if it doesn't exist
mkdir --parents "$BINARIES_DIR"

# Temporary download and extract
TEMP_TARBALL="$BINARIES_DIR/jdk21-$JDK_VERSION.tar.gz"

# Setup trap for cleanup
cleanup() {
    if [ -f "$TEMP_TARBALL" ]; then
        echo "Cleaning up temporary files..."
        rm --force "$TEMP_TARBALL"
    fi
}
trap cleanup EXIT

echo "Downloading JDK $JDK_VERSION from $URL..."
rm --force "$TEMP_TARBALL"
wget --output-document="$TEMP_TARBALL" "$URL"

echo "Extracting JDK..."
# Create a temporary directory for extraction
TEMP_EXTRACT_DIR="$BINARIES_DIR/jdk21_temp_$(date +%s)"
mkdir -p "$TEMP_EXTRACT_DIR"
tar -xzf "$TEMP_TARBALL" -C "$TEMP_EXTRACT_DIR"

# The tarball usually contains a single top-level directory like jdk-21.0.2+13
# Find that directory and move its contents
extracted_subdir=$(find "$TEMP_EXTRACT_DIR" -maxdepth 1 -mindepth 1 -type d)

# Move to the final destination
echo "Moving extracted files to $JDK_DEST_DIR..."
rm --recursive --force "$JDK_DEST_DIR"
mkdir -p "$JDK_DEST_DIR"
mv "$extracted_subdir"/* "$JDK_DEST_DIR/"

# Cleanup temp dir
rm -rf "$TEMP_EXTRACT_DIR"

if [ -f "$JAVA_BINARY" ]; then
    echo "JDK 21 installed successfully at $JDK_DEST_DIR"
    verify_installation "$JAVA_BINARY"
else
    echo "Error: Failed to install JDK 21."
    exit 1
fi
