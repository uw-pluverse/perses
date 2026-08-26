#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

if [[ ! -e "WORKSPACE" ]]; then
  echo "The script needs to be run in the root of the perses project."
  exit 1
fi

if [[ "$#" != 1 ]]; then
  echo "Usage: ${0} <public repo directory>"
  exit 1
fi

# parse argument
readonly PUBLIC_REPO_DIR=${1}

# check folder existence
if [ ! -d "$PUBLIC_REPO_DIR" ]; then
  echo "Directory $PUBLIC_REPO_DIR does not exists."
  exit 2
fi

# check if git repo
if ! git -C "$PUBLIC_REPO_DIR" rev-parse 2> /dev/null; then
  echo "Directory $PUBLIC_REPO_DIR is not a Git repo."
  exit 3
fi

# check if repo points to "github.com/perses-project/perses"
if ! (git -C "$PUBLIC_REPO_DIR" ls-remote --get-url | grep 'perses-project/perses' &> /dev/null); then
  echo "Git remote repo should point to \"perses-project/perses\"."
  exit 4
fi

# check if repo clean
if [[ -n $(git -C "$PUBLIC_REPO_DIR" status --short) ]]; then
  echo "Tree is dirty. Please commit changes first."
  exit 5
fi

# The content is exported from HEAD with git-archive instead of being copied
# from the working tree, so untracked and ignored files (build outputs, scratch
# files) cannot leak into the public repo, and the tree does not need to be
# cleaned first. Only committed content is published.

# update public repo first layer (folders & files)
for entry in $(git -C "$PUBLIC_REPO_DIR" ls-tree --name-only HEAD); do
  # delete the entry in the public repo.
  rm -rf "${PUBLIC_REPO_DIR:?}/${entry}"
  if git cat-file -e "HEAD:${entry}" 2> /dev/null; then
    git archive HEAD -- "${entry}" | tar -x -C "${PUBLIC_REPO_DIR}" || exit 6
  fi
done

# copy the tracked top-level files, including ones the public repo does not have yet.
readonly TOP_LEVEL_FILES=$(git ls-tree HEAD | awk '$2 == "blob" { print $4 }')
if [[ -n "${TOP_LEVEL_FILES}" ]]; then
  # shellcheck disable=SC2086
  git archive HEAD -- ${TOP_LEVEL_FILES} | tar -x -C "${PUBLIC_REPO_DIR}" || exit 6
fi
echo
echo "Done."
