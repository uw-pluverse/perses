#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if command -v git > /dev/null ; then
  GIT_COMMIT_HASH=$(git show --format="%H" --no-patch)
  GIT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
  if git diff-index --quiet HEAD -- ; then
    GIT_STATUS="Clean"
  else
    GIT_STATUS="Modified"
  fi
else
  GIT_COMMIT_HASH=""
  GIT_BRANCH=""
  GIT_STATUS=""
fi

echo "PERSES_GIT_COMMIT_HASH ${GIT_COMMIT_HASH}"
echo "PERSES_GIT_BRANCH ${GIT_BRANCH}"
echo "PERSES_GIT_STATUS ${GIT_STATUS}"
