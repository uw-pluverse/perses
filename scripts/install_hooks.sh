#!/usr/bin/env bash

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)

source "${SCRIPT_DIR}/constants.sh" || exit 1

# The hooks live in the versioned .githooks directory, so improving a hook
# propagates to every clone on pull; this script only has to point the clone at
# them, and presubmit.sh runs it so any clone that runs presubmit is covered.
git config core.hooksPath .githooks
