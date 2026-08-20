#!/usr/bin/env bash

# This script starts the Eclipse JDT Language Server (jdt.ls).
# It abstracts the complex Java command and arguments, allowing jdt.ls
# to be treated as a single executable similar to clangd.

# Enable safety flags
set -o errexit
set -o nounset
set -o pipefail

# Get the script directory
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)

# Target version 1.33.0
JDTLS_DIR="$SCRIPT_DIR/jdtls-1.33.0"

# Determine the workspace data directory
CREATED_DATA_DIR=""
if [[ -z "${JDTLS_DATA_DIR:-}" ]]; then
    # Determine a writable base directory for temporary files
    if [[ -n "${TEST_TMPDIR:-}" ]]; then
        TMP_BASE="$TEST_TMPDIR"
    elif [[ -n "${TMPDIR:-}" ]]; then
        TMP_BASE="$TMPDIR"
    else
        TMP_BASE="/tmp"
    fi
    # Create a unique temporary directory if none provided
    DATA_DIR=$(mktemp -d -p "$TMP_BASE" jdtls-data-XXXXXXXX)
    # Remember that we own this directory so it can be cleaned up on exit.
    CREATED_DATA_DIR="$DATA_DIR"
else
    DATA_DIR="$JDTLS_DATA_DIR"
    mkdir -p "$DATA_DIR"
fi

# Clean up the workspace directory we created when the server exits (normally or
# via a signal). Each reduction starts the server several times, and without this
# the unique mktemp directories accumulate indefinitely (hundreds of MB in /tmp).
# A caller-provided JDTLS_DATA_DIR is left untouched.
JDTLS_PID=""
cleanup() {
    if [[ -n "${JDTLS_PID}" ]]; then
        kill "${JDTLS_PID}" 2> /dev/null || true
        # Wait for the server to fully exit before deleting its workspace;
        # otherwise its shutdown writes race the removal and recreate the dir.
        wait "${JDTLS_PID}" 2> /dev/null || true
    fi
    if [[ -n "${CREATED_DATA_DIR}" ]]; then
        rm -rf "${CREATED_DATA_DIR}" || true
    fi
}
trap cleanup EXIT
trap 'exit 143' TERM
trap 'exit 130' INT

# Aggressively mask the home directory to avoid writing to read-only /home/cnsun
export HOME="$DATA_DIR"
export XDG_CONFIG_HOME="$DATA_DIR/.config"
export XDG_CACHE_HOME="$DATA_DIR/.cache"
export XDG_DATA_HOME="$DATA_DIR/.local/share"

# Ensure we use JDK 21 (from benchmark/install_jdk21.sh)
if [[ -z "${JDK21_DIR:-}" ]]; then
    export JAVA_HOME="$SCRIPT_DIR/jdk21"
else
    export JAVA_HOME="$JDK21_DIR"
fi
export PATH="$JAVA_HOME/bin:${PATH}"

# Run the language server using the bundled python script.
# This script handles complex JVM arguments and cascaded configuration.
# We also explicitly set user.home and headless mode via --jvm-arg.
# It is run as a child (not exec) so the cleanup trap above runs once the
# server exits; stdio is inherited, so the LSP stream still flows to the client.
# The explicit `<&0` is required: a backgrounded command in a non-interactive
# shell otherwise has its stdin redirected from /dev/null, which would starve the
# LSP server of the JSON-RPC stream coming from the client over stdin.
python3 "$JDTLS_DIR/bin/jdtls" \
    -data "$DATA_DIR" \
    --jvm-arg=-Duser.home="$DATA_DIR" \
    --jvm-arg=-Djava.awt.headless=true \
    --jvm-arg=-XX:TieredStopAtLevel=1 \
    "$@" <&0 &
JDTLS_PID=$!
wait "$JDTLS_PID"
