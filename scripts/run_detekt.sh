#!/usr/bin/env bash
# Deprecated: detekt is not helpful.

set -o nounset
set -o pipefail
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

readonly JAR="detekt_deploy.jar"
bazel build "//:${JAR}"

readonly KT_VERSION="1.8"
# DON'T use 'bazel run //:detekt_deploy.jar' due to its working directory
#     is not the root of the workspace.
java -jar bazel-bin/${JAR} \
    --input src,test,antlropt,version \
    --language-version "${KT_VERSION}" \
    --parallel || exit 1

echo "detekt is done."