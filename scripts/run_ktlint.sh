#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

source "./scripts/constants.sh"

bazel build "//:ktlint_deploy.jar"

KT_LINT_DIRS=""
for bazel_dir in "${BAZEL_DIRS[@]}" ; do
  KT_LINT_DIRS="${KT_LINT_DIRS} ${bazel_dir}/**/*.kt"
done
# DON'T use 'bazel run //:ktlint_deploy.jar' due to its working directory
#     is not the root of the workspace.
java -jar bazel-bin/ktlint_deploy.jar --format ${KT_LINT_DIRS} || exit 1

echo "ktlint is done."

bazel build "//:google_java_format_deploy.jar"

readonly FLAG_FILE=$(mktemp)
trap "rm ${FLAG_FILE}" EXIT
echo "--replace" > "${FLAG_FILE}"
for dir in "${BAZEL_DIRS[@]}" ; do
  echo "running google-java-format on directory ${dir}"
  find "${dir}" -name '*.java' >> "${FLAG_FILE}"
done
java -jar bazel-bin/google_java_format_deploy.jar "@${FLAG_FILE}"

echo "google-java-format is done."