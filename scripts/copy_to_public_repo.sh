#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

if [[ ! -e "WORKSPACE" ]] ; then
  echo "The script needs to be run in the root of the perses project."
  exit 1
fi

if [[ "$#" != 1 ]] ; then
  echo "Usage: ${0} <public repo directory>" 
  exit 1
fi

./scripts/git-clean.sh || exit 1

# parse argument
readonly PUBLIC_REPO_DIR=${1}

# check folder existence
if [ ! -d "$PUBLIC_REPO_DIR" ] ; then
  echo "Directory $PUBLIC_REPO_DIR does not exists."
  exit 2
fi

# check if git repo
if ! git -C "$PUBLIC_REPO_DIR" rev-parse 2>/dev/null ; then
  echo "Directory $PUBLIC_REPO_DIR is not a Git repo."
  exit 3
fi

# check if repo points to "github.com/perses-project/perses"
if ! ( git -C "$PUBLIC_REPO_DIR" ls-remote --get-url | grep 'perses-project/perses' &>/dev/null ) ; then
  echo "Git remote repo should point to \"perses-project/perses\"."
  exit 4
fi

# check if repo clean
if [[ -n $(git -C "$PUBLIC_REPO_DIR" status --short) ]]; then
  echo "Tree is dirty. Please commit changes first."
  exit 5
fi

# update public repo first layer (folders & files)
for entry in $(git -C "$PUBLIC_REPO_DIR" ls-tree --name-only HEAD); do
  # delete the entry in the public repo.
  rm -rf "${PUBLIC_REPO_DIR}/${entry}"
  cp -rf "$(basename "${entry}")" "${PUBLIC_REPO_DIR}/"
done

for entry in $(find . -maxdepth 1 -type f); do
  cp -f "${entry}" "${PUBLIC_REPO_DIR}/"
done
echo
echo "Done."
