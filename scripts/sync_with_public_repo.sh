#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script ${0} should be run in the root of the perse project"
  exit 1
fi

git pull

readonly BRANCH_TO_SYNC="master"
readonly CMD_LIST_REMOTES="git remote --verbose"
readonly PUBLIC_REPO="https://github.com/chengniansun/perses"
readonly PUBLIC_REMOTE_NAME="perses_public_repo"
readonly OLD_ALL_REMOTES=$(${CMD_LIST_REMOTES})
if [[ "${OLD_ALL_REMOTES}" != *"${PUBLIC_REPO}"* ]] ; then
  echo "The public remote has not been added. Adding it now."
  git remote add "${PUBLIC_REMOTE_NAME}" "${PUBLIC_REPO}"
fi

# Verify if the public remote exists.
echo "Verifying the public remote is successfully added."
readonly NEW_ALL_REMOTES=$(${CMD_LIST_REMOTES})
if [[ "${NEW_ALL_REMOTES}" != *"${PUBLIC_REPO}"* ]] ; then
  echo "The public remote was not added successfully."
  exit 1
fi

echo "Pulling from the public remote"
git pull "${PUBLIC_REMOTE_NAME}" "${BRANCH_TO_SYNC}"

echo "Pulling from the origin"
git pull "origin" "${BRANCH_TO_SYNC}"

echo "Pushing to the public origin"
git push "${PUBLIC_REMOTE_NAME}" "${BRANCH_TO_SYNC}"

echo "Removing the public remote"
git remote remove "${PUBLIC_REMOTE_NAME}"

echo "Verifying the public remote has been deleted successfully"
readonly FINAL_ALL_REMOTES=$(${CMD_LIST_REMOTES})
if [[ "${FINAL_ALL_REMOTES}" == *"${PUBLIC_REPO}"* ]] ; then
  echo "ERROR: The public repo is not deleted yet."
  exit 1
fi
echo "Sync is done successfully."
