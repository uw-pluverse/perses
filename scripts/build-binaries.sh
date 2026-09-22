#!/usr/bin/env bash
#
# Builds the reducer deploy jars and stages self-executable copies into bin/.
# Run directly (also invoked by benchmark_v2/perses_benchmark.py's build step), or
# source it to reuse `target_hashmap` / `build_binaries`; when sourced, nothing is
# built until the caller invokes build_binaries.

set -o pipefail
set -o nounset

readonly BINARIES_SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
source "${BINARIES_SCRIPT_DIR}/constants.sh" || exit 1

# Only targets this repository actually contains. //astra/... used to be here, but astra is not
# part of the public tree: it reaches a build through the wrapper's symlink overlay, so naming it
# here made this script fail on any checkout that has only the public repo -- with
# "no such package 'astra/cxx/src'", which points nowhere near the cause. Nothing in the benchmark
# harnesses consumes the astra jars; build them from the wrapper when you want the perses_java or
# perses_cxx CLI.
declare -A target_hashmap
target_hashmap["//src/org/perses:perses_deploy.jar"]="bazel-bin/src/org/perses/perses_deploy.jar"
target_hashmap["//src/org/perses:token_counter_deploy.jar"]="bazel-bin/src/org/perses/token_counter_deploy.jar"
# target_hashmap["//mimir/src/org/perses/mimir:mimir_deploy.jar"]="bazel-bin/mimir/src/org/perses/mimir/mimir_deploy.jar"

readonly BIN_DIR="${WORKSPACE_ROOT}/bin/"

# make_jar_self_executable.sh prepends exactly this many bytes of shebang to the bazel output.
readonly JAR_HEADER_BYTES=46

# Restaging is not free: it swaps the inode of a jar that a running container may be about to
# open (bin/ is bind-mounted into the benchmark image), and a concurrent sweep restages the same
# four jars once per worker. Bazel already no-ops an up-to-date build, so make staging no-op too
# when the staged jar is byte-for-byte what we would write. This is an exact content check, not a
# timestamp one, and costs ~0.4s for all four jars.
is_staged_jar_current() {
  local source_jar="${1}" staged_jar="${2}"
  [[ -f "${staged_jar}" ]] || return 1
  local source_size staged_size
  source_size=$(stat -c %s "${source_jar}")
  staged_size=$(stat -c %s "${staged_jar}")
  [[ $((source_size + JAR_HEADER_BYTES)) -eq ${staged_size} ]] || return 1
  tail -c "+$((JAR_HEADER_BYTES + 1))" "${staged_jar}" | cmp -s - "${source_jar}"
}

build_binaries() {
  local bazel_target source_jar_path source_jar_basename exe_file_path
  for bazel_target in "${!target_hashmap[@]}" ; do
    bazelisk build "${bazel_target}"
    source_jar_path="${target_hashmap[$bazel_target]}"
    source_jar_basename=$(basename ${source_jar_path})
    exe_file_path="${BIN_DIR}/${source_jar_basename}"
    if is_staged_jar_current "${source_jar_path}" "${exe_file_path}" ; then
      echo "Already up to date: ${exe_file_path}"
      continue
    fi
    "${WORKSPACE_ROOT}/scripts/make_jar_self_executable.sh" "${source_jar_path}" "${exe_file_path}"
    echo "Created an executable file ${exe_file_path}"
  done
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
  set -o xtrace
  build_binaries
fi
