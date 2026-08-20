# This file is intended to be sourced by other script files. It provides a
# helper for enumerating the source files changed in the current checkout, used
# to scope formatters/linters to only what changed instead of the whole tree.
#
# Prerequisite: constants.sh must already be sourced so that BAZEL_DIRS and
# WORKSPACE_ROOT are defined.

# The ref to diff against: the merge-base with master (so committed changes on a
# feature branch are included), falling back to HEAD when there is no master
# (e.g. a detached or fresh checkout), in which case only working-tree edits show.
changed_files_base_ref() {
  git merge-base HEAD master 2> /dev/null || git rev-parse HEAD
}

# Prints, one per line, the absolute paths of changed source files whose
# extension matches any of the arguments (e.g. `collect_changed_files kt java`).
#
# The git scan is scoped to BAZEL_DIRS so vendored/third-party files elsewhere
# are left untouched (matching the historical full-tree behavior) and broken
# symlinks elsewhere in the tree are not traversed. The reported set is the union
# of (a) files differing from the base ref, covering committed and uncommitted
# edits, and (b) new untracked files, which `git diff` does not report. Absolute
# paths are emitted because some consumers (e.g. `bazelisk run //:ktlint`) do not
# execute with the workspace root as their working directory.
collect_changed_files() {
  local exts=("$@") base file ext
  base=$(changed_files_base_ref)
  {
    git diff --name-only --diff-filter=ACMR "${base}" -- "${BAZEL_DIRS[@]}"
    git ls-files --others --exclude-standard -- "${BAZEL_DIRS[@]}"
  } | sort -u | while IFS= read -r file; do
    [[ -f "${file}" ]] || continue
    for ext in "${exts[@]}"; do
      if [[ "${file}" == *."${ext}" ]]; then
        printf '%s/%s\n' "${WORKSPACE_ROOT}" "${file}"
        break
      fi
    done
  done
}
