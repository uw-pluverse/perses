#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

readonly SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
source "${SCRIPT_DIR}/constants.sh" || exit 1
source "${SCRIPT_DIR}/changed_files.sh" || exit 1

# Formatting output is governed not only by the source files but also by the
# formatter rule config (.editorconfig) and the pinned formatter versions (in
# MODULE.bazel / the root BUILD). When any of those change, the formatting of
# *unchanged* files may shift too, so a changed-files-only pass would leave the
# rest of the tree inconsistent. Returns success when such a config change is
# present relative to the base ref.
formatting_config_changed() {
  local base
  base=$(changed_files_base_ref)
  # ktlint rule config: any change forces a full pass.
  if ! git diff --quiet "${base}" -- .editorconfig; then
    return 0
  fi
  # Formatter version pins / target definitions live alongside unrelated content
  # in MODULE.bazel and the root BUILD, so only count formatter-related lines;
  # unrelated dependency or BUILD edits must not force a full pass.
  if git diff "${base}" -- MODULE.bazel BUILD \
    | grep -qiE '^[+-].*(ktlint|googlejavaformat|google-java-format|google_java_format)'; then
    return 0
  fi
  return 1
}

# By default only the files changed relative to the base branch (including
# uncommitted working-tree edits) are formatted, which keeps presubmit fast.
# Pass --all to format every source file in the tree (e.g. for a full sweep).
FORMAT_ALL=0
if [[ "${1:-}" == "--all" ]]; then
  FORMAT_ALL=1
elif formatting_config_changed; then
  echo "Formatter config or version changed; formatting all source files."
  FORMAT_ALL=1
fi

#
# ktlint (Kotlin)
#
bazelisk build "//:ktlint_deploy.jar"

if [[ "${FORMAT_ALL}" -eq 1 ]]; then
  KT_LINT_ARGS=""
  for bazel_dir in "${ABS_BAZEL_DIRS[@]}"; do
    KT_LINT_ARGS="${KT_LINT_ARGS} ${bazel_dir}/**/*.kt"
  done
  # DON'T use 'bazelisk run //:ktlint_deploy.jar' due to its working directory
  #     is not the root of the workspace.
  bazelisk run //:ktlint -- --format ${KT_LINT_ARGS} || exit 1
else
  mapfile -t KT_FILES < <(collect_changed_files kt)
  if [[ "${#KT_FILES[@]}" -eq 0 ]]; then
    echo "No changed Kotlin files to format."
  else
    bazelisk run //:ktlint -- --format "${KT_FILES[@]}" || exit 1
  fi
fi

echo "ktlint is done."

#
# google-java-format (Java)
#
bazelisk build "//:google_java_format_deploy.jar"

readonly FLAG_FILE=$(mktemp)
trap "rm ${FLAG_FILE}" EXIT
echo "--replace" > "${FLAG_FILE}"

JAVA_FILE_COUNT=0
if [[ "${FORMAT_ALL}" -eq 1 ]]; then
  for dir in "${BAZEL_DIRS[@]}"; do
    echo "running google-java-format on directory ${dir}"
    find "${dir}" -name '*.java' >> "${FLAG_FILE}"
  done
  JAVA_FILE_COUNT=1
else
  mapfile -t JAVA_FILES < <(collect_changed_files java)
  JAVA_FILE_COUNT="${#JAVA_FILES[@]}"
  if [[ "${JAVA_FILE_COUNT}" -gt 0 ]]; then
    printf '%s\n' "${JAVA_FILES[@]}" >> "${FLAG_FILE}"
  fi
fi

if [[ "${JAVA_FILE_COUNT}" -eq 0 ]]; then
  echo "No changed Java files to format."
else
  # google-java-format reaches into javac internals, which JDK 16+ strong
  # encapsulation blocks without these exports.
  java \
    --add-exports jdk.compiler/com.sun.tools.javac.api=ALL-UNNAMED \
    --add-exports jdk.compiler/com.sun.tools.javac.code=ALL-UNNAMED \
    --add-exports jdk.compiler/com.sun.tools.javac.file=ALL-UNNAMED \
    --add-exports jdk.compiler/com.sun.tools.javac.parser=ALL-UNNAMED \
    --add-exports jdk.compiler/com.sun.tools.javac.tree=ALL-UNNAMED \
    --add-exports jdk.compiler/com.sun.tools.javac.util=ALL-UNNAMED \
    -jar bazel-bin/google_java_format_deploy.jar "@${FLAG_FILE}"
fi

echo "google-java-format is done."
