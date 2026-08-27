#!/usr/bin/env bash
#
# Assert the tool versions the dev image is supposed to pin. Runs INSIDE the container; the host
# entry point is test_image.sh, which bind-mounts this file in.
#
# These versions are what the committed golden files were generated against -- the c/cpp toy
# oracles grep gcc/clang diagnostics -- so a drift here would otherwise show up much later as
# presubmit silently rewriting goldens.

set -o nounset
set -o pipefail

# The bazel release the image should have pre-warmed. test_image.sh reads it from .bazelversion,
# which is the single source of truth for both this check and the docker build.
: "${EXPECTED_BAZEL_VERSION:?must be set by test_image.sh}"

failures=0

# expect <expected-substring> <command...>: run the command, capturing stdout and stderr (several
# of these tools report their version on stderr), and require the substring to appear.
expect() {
  local expected="$1"
  shift
  local output
  output=$("$@" 2>&1 | head -3) || true
  if [[ "${output}" == *"${expected}"* ]]; then
    printf 'ok       %-14s %s\n' "$1" "${expected}"
  else
    printf 'FAILED   %-14s expected %-30s got: %s\n' "$1" "${expected}" "${output//$'\n'/ | }"
    failures=$((failures + 1))
  fi
}

# present <tool>: check_prerequisite.sh only requires these to be on the PATH.
present() {
  if command -v "$1" > /dev/null 2>&1; then
    printf 'ok       %-14s present\n' "$1"
  else
    printf 'FAILED   %-14s not on PATH\n' "$1"
    failures=$((failures + 1))
  fi
}

expect "13.3.0" gcc --version
expect "13.3.0" g++ --version
expect "clang version 18.1.8" clang --version
expect "clang version 18.1.8" clang++ --version
expect "clang-format version 18.1.8" clang-format --version
expect "clangd version 18.1.8" clangd-18 --version
expect "rustc 1.96.1" rustc --version
# //kitten/test/org/perses/fuzzer/rust:RustcVersionTest runs `rustc +nightly --version --verbose`.
expect "nightly" rustc +nightly --version
expect "go1.22" go version
expect 'openjdk version "17' java -version
expect "javac 17" javac -version
expect "1.0.34" wat2wasm --version
expect "wasmedge version 0.14.1" wasmedge -v
expect "creduce 2.11.0" creduce --version
expect "LCOV version 2.0" lcov --version
expect "gcovr 7.0" gcovr --version
expect "version 2.11.12" scala -version
expect "ruby 3.2" ruby --version
expect "Python 3.12" python3 --version

# bazelisk takes its version from the workspace's .bazelversion, and this container is started
# without a workspace, so a bare `bazelisk --version` would resolve to "latest" and download it.
# USE_BAZEL_VERSION names the version explicitly instead. That alone would still pass by
# downloading, so first assert the release the image pre-warmed is already on disk.
if [[ -e "${BAZELISK_HOME}/downloads/metadata/bazelbuild/bazel-${EXPECTED_BAZEL_VERSION}-linux-x86_64" ]]; then
  printf 'ok       %-14s bazel %s pre-warmed\n' "bazelisk" "${EXPECTED_BAZEL_VERSION}"
else
  printf 'FAILED   %-14s bazel %s not pre-warmed under %s\n' \
    "bazelisk" "${EXPECTED_BAZEL_VERSION}" "${BAZELISK_HOME}"
  failures=$((failures + 1))
fi
export USE_BAZEL_VERSION="${EXPECTED_BAZEL_VERSION}"
expect "bazel ${EXPECTED_BAZEL_VERSION}" bazelisk --version

present rustfmt
present valgrind
present javap
present ps
present git
present mvn
# The three benchmark_v2/install_*.sh scripts that populate benchmark_v2/binaries/ download with
# wget, not curl, so its absence only surfaces on a checkout that has not been populated yet.
present wget

# The interactive-debugging layer. Not needed to build or test perses, so a missing one is not a
# golden-fidelity problem -- but it is silent until the moment a failure has to be diagnosed.
present gdb
present strace
present less
present file
present jq

if [[ "${failures}" -ne 0 ]]; then
  echo "${failures} version check(s) failed."
  exit 1
fi

echo "All version checks passed."
