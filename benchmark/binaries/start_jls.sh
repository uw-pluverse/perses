#!/usr/bin/env bash

# This script starts George Fraser's Java Language Server (JLS).
# It provides a compatible interface for MimirDependencyAnalyzer.

set -o errexit
set -o nounset
set -o pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
JLS_DIR="$SCRIPT_DIR/java-language-server"


# Mask environment

# Cleanup daemon
(
    while kill -0 $$ 2>/dev/null; do sleep 5; done
    rm -rf "$DATA_DIR"
) &

# JLS needs JDK 21
export JAVA_HOME="$SCRIPT_DIR/jdk21"
export PATH="$JAVA_HOME/bin:$PATH"

exec "$JLS_DIR/dist/lang_server_linux.sh" "$@"
