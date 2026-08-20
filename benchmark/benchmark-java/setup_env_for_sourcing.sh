#!/usr/bin/env bash
#
# Portable environment setup for sourcing.
# Supports both bash and zsh.
# Usage: source benchmark/benchmark-java/setup-env-for-sourcing.sh

# Get the absolute directory where this script is located
# This logic handles both bash and zsh
if [ -n "$BASH_SOURCE" ]; then
    SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
elif [ -n "$ZSH_VERSION" ]; then
    SCRIPT_DIR="$(cd "$(dirname "${(%):-%x}")" && pwd)"
else
    # Fallback to $0 if possible
    SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
fi

# Set the environment variable for the checker framework
export CHECKER_1_9_11="${SCRIPT_DIR}/lib/checkerframework-1.9.11"
export CHECKER_1_9_13="${SCRIPT_DIR}/lib/checkerframework-1.9.13"
export CHECKER_2_1_10="${SCRIPT_DIR}/lib/checkerframework-2.1.10"
export CHECKER_3_0_1="${SCRIPT_DIR}/lib/checkerframework-3.0.1"
export CHECKER_3_6_0="${SCRIPT_DIR}/lib/checkerframework-3.6.0"
export CHECKER_3_7_1="${SCRIPT_DIR}/lib/checkerframework-3.7.1"
export CHECKER_3_12="${SCRIPT_DIR}/lib/checkerframework-3.12.0"
export CHECKER_3_35_0="${SCRIPT_DIR}/lib/checkerframework-3.35.0"
export CHECKER_3_36_0="${SCRIPT_DIR}/lib/checkerframework-3.36.0"
export CHECKER_3_42_0="${SCRIPT_DIR}/lib/checkerframework-3.42.0"

# Set the environment variable for JDK 8 (installed via benchmark/install_jdk8.sh)
export JDK8_DIR="$(dirname "$SCRIPT_DIR")/binaries/jdk8"
export JDK17_DIR="$(dirname "$SCRIPT_DIR")/binaries/jdk17"
export JDK21_DIR="$(dirname "$SCRIPT_DIR")/binaries/jdk21"

# Gradle, used to run the NullAway benchmarks (installed via benchmark/install_gradle.sh)
export GRADLE_DIR="$(dirname "$SCRIPT_DIR")/binaries/gradle"

# Add start_jdtls.sh to PATH (located in benchmark/binaries/)
export PATH="$(dirname "$SCRIPT_DIR")/binaries:${PATH}"

echo "Environment variable CHECKER_3_12 has been set to: ${CHECKER_3_12}"
echo "Environment variable CHECKER_3_0_1 has been set to: ${CHECKER_3_0_1}"
echo "Environment variable CHECKER_1_9_11 has been set to: ${CHECKER_1_9_11}"
echo "Environment variable CHECKER_1_9_13 has been set to: ${CHECKER_1_9_13}"
echo "Environment variable JDK8_DIR has been set to: ${JDK8_DIR}"
echo "Environment variable JDK21_DIR has been set to: ${JDK21_DIR}"
echo "Added $(dirname "$SCRIPT_DIR")/binaries to PATH."

# ---------------------------------------------------------------------------
# Validate that everything the setup exposes is actually usable, and install
# anything that is missing via its installer script in benchmark/.
#
# Three kinds of checks:
#   1. Launcher scripts that must be resolvable on PATH (the wrappers in
#      benchmark/binaries that this setup just added to PATH) plus the external
#      tools they need at runtime. These are committed / system-provided, so a
#      failure is reported but cannot be auto-fixed here.
#   2. Bundled payloads installed by benchmark/install_*.sh (the JDKs, jdt.ls,
#      and the java-language-server). When one of these is missing, the
#      corresponding installer is invoked and the check is retried.
#
# This block never `exit`s, because the script is meant to be sourced and an
# `exit` would close the caller's shell. Installers are run as subprocesses
# (`bash <installer>`), so their own `exit` calls do not affect this shell.
__setup_env_validation_failed=0
__benchmark_dir="$(dirname "$SCRIPT_DIR")"
__binaries_dir="${__benchmark_dir}/binaries"

# Confirm a command resolves on PATH, and (optionally) that it resolves to the
# expected absolute path so a same-named binary elsewhere on PATH can't shadow
# the bundled one.
__check_on_path() {
    __cmd="$1"
    __expected="$2"
    __resolved="$(command -v "$__cmd" 2> /dev/null)"
    if [ -z "$__resolved" ]; then
        echo "ERROR: '$__cmd' is NOT available on PATH after setup." >&2
        __setup_env_validation_failed=1
        return
    fi
    if [ -n "$__expected" ] && [ "$__resolved" != "$__expected" ]; then
        echo "WARNING: '$__cmd' resolves to '$__resolved', expected '$__expected' (shadowed by another entry on PATH)." >&2
    fi
    echo "OK: '$__cmd' -> $__resolved"
}

# Ensure an installed payload exists; if not, run its installer and re-check.
#   $1 label, $2 test flag (-f/-d/-x), $3 path to test, $4 installer script name
__ensure_installed() {
    __label="$1"
    __flag="$2"
    __path="$3"
    __installer="${__benchmark_dir}/$4"
    if [ "$__flag" "$__path" ]; then
        echo "OK: $__label -> $__path"
        return
    fi
    echo "MISSING: $__label not found at $__path; running installer $4 ..." >&2
    if [ ! -f "$__installer" ]; then
        echo "ERROR: installer not found: $__installer" >&2
        __setup_env_validation_failed=1
        return
    fi
    if bash "$__installer"; then
        if [ "$__flag" "$__path" ]; then
            echo "OK (installed): $__label -> $__path"
        else
            echo "ERROR: $4 completed but $__label is still missing at $__path" >&2
            __setup_env_validation_failed=1
        fi
    else
        echo "ERROR: installer $4 failed for $__label." >&2
        __setup_env_validation_failed=1
    fi
}

# 1. Launcher wrappers on PATH and the external tools they invoke at runtime.
#    (Committed in the repo / provided by the system; no installer to run.)
__check_on_path "start_jdtls.sh" "${__binaries_dir}/start_jdtls.sh"
__check_on_path "start_jls.sh"   "${__binaries_dir}/start_jls.sh"
__check_on_path "python3" ""

# 2. Bundled payloads; auto-installed via benchmark/install_*.sh when missing.
# Checker Framework dists fetched on demand by install_checkers.sh (large binaries kept out of git).
__ensure_checker() {
    __ck_version="$1"
    __ck_jar="${SCRIPT_DIR}/lib/checkerframework-${__ck_version}/checker.jar"
    if [ -f "${__ck_jar}" ]; then
        echo "OK: Checker Framework ${__ck_version} -> ${__ck_jar}"
        return
    fi
    echo "MISSING: Checker Framework ${__ck_version} not found; running install_checkers.sh ${__ck_version} ..." >&2
    if bash "${__benchmark_dir}/install_checkers.sh" "${__ck_version}"; then
        if [ -f "${__ck_jar}" ]; then
            echo "OK (installed): Checker Framework ${__ck_version} -> ${__ck_jar}"
        else
            echo "ERROR: install_checkers.sh ${__ck_version} completed but ${__ck_jar} is still missing" >&2
            __setup_env_validation_failed=1
        fi
    else
        echo "ERROR: install_checkers.sh ${__ck_version} failed." >&2
        __setup_env_validation_failed=1
    fi
}
__ensure_checker 1.9.11
__ensure_checker 1.9.13
__ensure_checker 2.1.10
__ensure_checker 3.0.1
__ensure_checker 3.6.0
__ensure_checker 3.7.1
__ensure_checker 3.12.0
__ensure_checker 3.35.0
__ensure_checker 3.36.0
__ensure_checker 3.42.0

__ensure_installed "JDK 8"                 -x "${JDK8_DIR}/bin/java"                                  install_jdk8.sh
__ensure_installed "JDK 17"                -x "${JDK17_DIR}/bin/java"                                 install_jdk17.sh
__ensure_installed "JDK 21"                -x "${JDK21_DIR}/bin/java"                                 install_jdk21.sh
__ensure_installed "Gradle"                -x "${GRADLE_DIR}/bin/gradle"                              install_gradle.sh
__ensure_installed "jdt.ls"                -f "${__binaries_dir}/jdtls-1.33.0/bin/jdtls"             install_jdtls.sh
__ensure_installed "java-language-server"  -f "${__binaries_dir}/java-language-server/dist/lang_server_linux.sh" install_jls.sh

if [ "$__setup_env_validation_failed" -ne 0 ]; then
    echo "setup_env_for_sourcing.sh: one or more required binaries are unavailable; see errors above." >&2
else
    echo "setup_env_for_sourcing.sh: all required binaries are available."
fi

# Avoid leaking helper names/state into the caller's interactive shell.
unset -f __check_on_path __ensure_installed __ensure_checker 2> /dev/null
unset __setup_env_validation_failed __benchmark_dir __binaries_dir __cmd __expected __resolved __label __flag __path __installer __ck_version __ck_jar 2> /dev/null
