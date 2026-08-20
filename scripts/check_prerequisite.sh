#!/usr/bin/env bash
#
# scripts/check_prerequisite.sh
# Check whether all required tools are installed.
#

set -o pipefail
set -o nounset

readonly TOOLS=(
  "clangd-18"
  "java"
  "javap"
  "creduce"
  "gcc"
  "clang"
  "clang-format"
  "go"
  "python3"
  "ps"
  "ruby"
  "rustc"
  "rustfmt"
  "scala"
  "wat2wasm"
  "wasmedge"
  "lcov"
  "gcovr"
  )

missing=""
for tool in "${TOOLS[@]}"; do
  if ! command -v "${tool}" > /dev/null 2>&1; then
    missing="${missing} ${tool}"
  fi
done

if [[ "${missing}" != "" ]]; then
  echo "The following tools are missing: ${missing}"
  exit 1
fi

readonly JAVA_VERSION=$(java -version 2>&1 | head -1 | cut -d'"' -f2 | sed '/^1\./s///' | cut -d'.' -f1)
if [[ "${JAVA_VERSION}" -lt "11" ]]; then
  echo "The minimum java version should be 11. The current version is ${JAVA_VERSION}"
  exit 1
fi

if ! wasmedge -v > /dev/null ; then
  echo "wasmedge is not properly installed."
  exit 1
fi

# Determine the repository root directory
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" > /dev/null 2>&1 && pwd)
source "${SCRIPT_DIR}/constants.sh"

# Bazel refuses to load //benchmark_v2/binaries until jdk21, jdtls and the java language
# server exist there: its BUILD globs them with the default allow_empty = False. So an
# incomplete install breaks `bazel build //benchmark_v2/...`, not just an experiment.

# Check for JDK 21 in benchmark_v2/binaries/ as it's required for some experiments.
check_jdk21() {
  local java_binary="${WORKSPACE_ROOT}/benchmark_v2/binaries/jdk21/bin/java"
  local install_script="${WORKSPACE_ROOT}/benchmark_v2/install_jdk21.sh"

  if [[ ! -f "${java_binary}" ]]; then
    echo "JDK 21 is not installed. Attempting to install..."
    if ! bash "${install_script}"; then
      echo "Failed to install JDK 21."
      return 1
    fi
  fi

  # Verify version
  local version_output=$("${java_binary}" -version 2>&1)
  if [[ "${version_output}" != *"openjdk version \"21.0.2\""* ]]; then
    echo "JDK 21 version mismatch or not properly installed. Attempting to reinstall..."
    if ! bash "${install_script}"; then
      echo "Failed to reinstall JDK 21."
      return 1
    fi
  fi
  return 0
}

# Check for clangd in benchmark_v2/binaries/ as it's required for C++ semantic analysis.
check_clangd() {
  local clangd_binary="${WORKSPACE_ROOT}/benchmark_v2/binaries/clangd-18/bin/clangd"
  local install_script="${WORKSPACE_ROOT}/benchmark_v2/install_clangd.sh"

  if [[ ! -f "${clangd_binary}" ]]; then
    echo "clangd is not installed. Attempting to install..."
    if ! bash "${install_script}"; then
      echo "Failed to install clangd."
      return 1
    fi
  fi

  # Verify version
  local version_output=$("${clangd_binary}" --version 2>&1)
  if [[ "${version_output}" != *"clangd version 18.1.3"* ]]; then
    echo "clangd version mismatch or not properly installed. Attempting to reinstall..."
    if ! bash "${install_script}"; then
      echo "Failed to reinstall clangd."
      return 1
    fi
  fi
  return 0
}

check_jdtls() {
  local start_script="${WORKSPACE_ROOT}/benchmark_v2/binaries/start_jdtls.sh"
  local install_script="${WORKSPACE_ROOT}/benchmark_v2/install_jdtls.sh"

  # Initial verification: try to start it.
  # timeout returns 124 (SIGTERM) or 137 (SIGKILL) if it timed out, which means it started properly.
  # If it exits with 0 quickly, it might also be fine, though unusual for an LSP server.
  #
  # We wrap in { ... } 2>/dev/null to suppress the "Killed" diagnostic message from the parent
  # shell when timeout sends SIGKILL to the process.
  { timeout --kill-after=5s 2s "${start_script}" > /dev/null 2>&1; } 2>/dev/null
  local exit_code=$?
  
  if [[ ${exit_code} -ne 124 && ${exit_code} -ne 137 && ${exit_code} -ne 0 ]]; then
    echo "jdt.ls is not properly installed or fails to start (exit code: ${exit_code}). Attempting to install/repair..."
    if ! bash "${install_script}"; then
      echo "Failed to install jdt.ls."
      return 1
    fi
    # Final verification after installation
    { timeout --kill-after=5s 2s "${start_script}" > /dev/null 2>&1; } 2>/dev/null
    exit_code=$?
    if [[ ${exit_code} -ne 124 && ${exit_code} -ne 137 && ${exit_code} -ne 0 ]]; then
      echo "jdt.ls still fails to start after installation (exit code: ${exit_code})."
      return 1
    fi
  fi
  return 0
}

check_jls() {
  local start_script="${WORKSPACE_ROOT}/benchmark_v2/binaries/start_jls.sh"
  local install_script="${WORKSPACE_ROOT}/benchmark_v2/install_jls.sh"

  # Initial verification: try to start it.
  # timeout returns 124 (SIGTERM) if it timed out, which means it started properly.
  { timeout --kill-after=5s 2s "${start_script}" > /dev/null 2>&1; } 2>/dev/null
  local exit_code=$?
  
  if [[ ${exit_code} -ne 124 && ${exit_code} -ne 137 && ${exit_code} -ne 0 ]]; then
    echo "jls is not properly installed or fails to start (exit code: ${exit_code}). Attempting to install/repair..."
    if ! bash "${install_script}"; then
      echo "Failed to install jls."
      return 1
    fi
    # Final verification after installation
    { timeout --kill-after=5s 2s "${start_script}" > /dev/null 2>&1; } 2>/dev/null
    exit_code=$?
    if [[ ${exit_code} -ne 124 && ${exit_code} -ne 137 && ${exit_code} -ne 0 ]]; then
      echo "jls still fails to start after installation (exit code: ${exit_code})."
      return 1
    fi
  fi
  return 0
}

if ! check_jdk21; then
  exit 1
fi

if ! check_clangd; then
  exit 1
fi

if ! check_jdtls; then
  exit 1
fi

if ! check_jls; then
  exit 1
fi

echo "${0} passed successfully."
exit 0
