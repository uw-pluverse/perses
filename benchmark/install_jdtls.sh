#!/usr/bin/env bash

# This script downloads and installs the Eclipse JDT Language Server (jdt.ls)
# into the benchmark/binaries directory to support Java program reduction
# for the mimir feature.

# Enable safety flags with long names
set -o errexit
set -o nounset
set -o pipefail

# The jdt.ls build to download. The old 1.33.0 milestone build
# (jdt-language-server-1.33.0-202402151717) was pruned from Eclipse's download and
# archive servers (404). Eclipse keeps only recent per-build tarballs, so we pin a
# specific snapshot build that is currently hosted -- not the moving "latest"
# alias, which would make the installed jdt.ls version nondeterministic.
JDTLS_DOWNLOAD_VERSION="1.54.0"
JDTLS_DOWNLOAD_BUILD="202511200503"
DOWNLOAD_URL="https://download.eclipse.org/jdtls/snapshots/jdt-language-server-${JDTLS_DOWNLOAD_VERSION}-${JDTLS_DOWNLOAD_BUILD}.tar.gz"

# Install directory name. Kept as jdtls-1.33.0, independent of the downloaded build
# above, because start_jdtls.sh, //benchmark/binaries:BUILD, and the benchmark-java
# env setup all reference that path.
JDTLS_VERSION="1.33.0"

# Get the directory where this script is located
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
BINARIES_DIR="$SCRIPT_DIR/binaries"
JDTLS_DEST_DIR="$BINARIES_DIR/jdtls-$JDTLS_VERSION"

# Function to verify jdtls installation
verify_installation() {
    local dest_dir=$1
    echo "Verifying jdt.ls installation in $dest_dir..."
    # Check for the presence of the launcher JAR in the plugins directory
    local launcher=$(find "$dest_dir/plugins" -name "org.eclipse.equinox.launcher_*.jar" | head -n 1)
    if [ -f "$launcher" ]; then
        echo "Successfully found launcher: $(basename "$launcher")"
    else
        echo "Error: Could not find Equinox launcher in $dest_dir/plugins"
        exit 1
    fi
}

if [ -d "$JDTLS_DEST_DIR" ]; then
    echo "jdt.ls $JDTLS_VERSION is already installed at $JDTLS_DEST_DIR"
    verify_installation "$JDTLS_DEST_DIR"
    exit 0
fi

echo "Installing jdt.ls $JDTLS_VERSION..."

# Create binaries directory if it doesn't exist
mkdir --parents "$BINARIES_DIR"

# Temporary download and extract
TEMP_TARBALL="$BINARIES_DIR/jdtls-$JDTLS_VERSION.tar.gz"

# Setup trap for cleanup
cleanup() {
    if [ -f "$TEMP_TARBALL" ]; then
        echo "Cleaning up temporary files..."
        rm --force "$TEMP_TARBALL"
    fi
}
trap cleanup EXIT

echo "Downloading jdt.ls $JDTLS_VERSION from $DOWNLOAD_URL..."
rm --force "$TEMP_TARBALL"
wget --output-document="$TEMP_TARBALL" "$DOWNLOAD_URL"

echo "Extracting jdt.ls..."
# Create a temporary directory for extraction
TEMP_EXTRACT_DIR="$BINARIES_DIR/jdtls_temp_$(date +%s)"
mkdir -p "$TEMP_EXTRACT_DIR"
tar -xzf "$TEMP_TARBALL" -C "$TEMP_EXTRACT_DIR"

# Move to the final destination
echo "Moving extracted files to $JDTLS_DEST_DIR..."
rm --recursive --force "$JDTLS_DEST_DIR"
mv "$TEMP_EXTRACT_DIR" "$JDTLS_DEST_DIR"

if [ -d "$JDTLS_DEST_DIR" ]; then
    echo "jdt.ls installed successfully at $JDTLS_DEST_DIR"
    verify_installation "$JDTLS_DEST_DIR"
else
    echo "Error: Failed to install jdt.ls."
    exit 1
fi
