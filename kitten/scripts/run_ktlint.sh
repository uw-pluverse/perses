#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

bazelisk build "//:ktlint_deploy.jar"

java -jar bazel-bin/ktlint_deploy.jar --format \
    "kitten/src/**/*.kt" \
    "kitten/test/**/*.kt" || exit 1

echo "ktlint is done."

bazelisk build "//:google_java_format_deploy.jar"

readonly FLAG_FILE=$(mktemp)
trap "rm ${FLAG_FILE}" EXIT
echo "--replace" > "${FLAG_FILE}"
for dir in "kitten/src" "kitten/test" ; do
  echo "running google-java-format on directory ${dir}"
  find "${dir}" -name '*.java' >> "${FLAG_FILE}"
done
java -jar bazel-bin/google_java_format_deploy.jar "@${FLAG_FILE}"

echo "google-java-format is done."
