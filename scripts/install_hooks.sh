#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit
set -o xtrace

if [[ ! -e "WORKSPACE" ]] ; then
  echo "ERROR: This script should be run in the root folder of the project."
  exit 1
fi

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

readonly PRESUBMIT_SCRIPT=".git/hooks/pre-commit"

cat > "${PRESUBMIT_SCRIPT}" <<EOF
#!/usr/bin/env bash

./scripts/cleanup.sh

EOF

chmod +x "${PRESUBMIT_SCRIPT}"

