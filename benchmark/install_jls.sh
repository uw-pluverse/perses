#!/bin/bash
# Script to install George Fraser's java-language-server (JLS)

set -o errexit
set -o nounset
set -o pipefail

# Get the directory where this script is located
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
BINARIES_DIR="$SCRIPT_DIR/binaries"
TARGET_DIR="$BINARIES_DIR/java-language-server"

# Ensure binaries directory exists
mkdir -p "$BINARIES_DIR"

# Pin to a specific commit for determinism
# This commit is from Mar 21, 2026
JLS_COMMIT="51a8034"

if [ -d "$TARGET_DIR/.git" ]; then
    echo "java-language-server already exists at $TARGET_DIR. Restoring source and updating..."
    cd "$TARGET_DIR"
    git fetch
    git checkout "$JLS_COMMIT"
    git reset --hard "$JLS_COMMIT"
    git clean -fd
else
    echo "Cloning java-language-server..."
    rm -rf "$TARGET_DIR"
    git clone https://github.com/georgewfraser/java-language-server "$TARGET_DIR"
    cd "$TARGET_DIR"
    git checkout "$JLS_COMMIT"
fi

echo "Building java-language-server with JDK 21 followed by Mimir patches..."

# Patch JavaLanguageServer.java to bypass InferConfig instantiation completely
# This is the most "complete" way to disable InferConfig.
# We replace the entire else block that instantiates InferConfig with a direct return.
# We use a range-based sed to replace from the "Otherwise" comment to the closing brace.
sed -i '/\/\/ Otherwise, combine inference/,/}/c\        else { javaEndProgress(); return new JavaCompilerService(classPath, Collections.emptySet(), addExports); }' src/main/java/org/javacs/JavaLanguageServer.java

# Use JDK 21 for building
export JAVA_HOME="$BINARIES_DIR/jdk21"
export PATH="$JAVA_HOME/bin:$PATH"

# Download platform-specific JDK jars (JLS needs these to talk to javac)
# Using linux as the default platform
./scripts/download_linux_jdk.sh
./scripts/link_linux.sh

# Build with Maven
mvn package -DskipTests

# Fix the hardcoded protobuf jar version in launch_linux.sh
PROTO_JAR=$(basename "$TARGET_DIR"/dist/classpath/protobuf-java-*.jar)
sed -i "s/protobuf-java-[^:]*\.jar/$PROTO_JAR/g" "$TARGET_DIR/dist/launch_linux.sh"

echo "Cleaning up JLS directory, keeping only dist..."
# Use find to delete everything except the 'dist' directory
# This ensures .git and all other hidden files/directories are removed
find "$TARGET_DIR" -maxdepth 1 ! -name 'dist' ! -name "$(basename "$TARGET_DIR")" -exec rm -rf {} +

echo "java-language-server installed and cleaned up successfully at $TARGET_DIR"
echo "Launch script: $TARGET_DIR/dist/lang_server_linux.sh"
