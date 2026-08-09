#!/usr/bin/env bash
#
# Copyright (C) 2018-2025 University of Waterloo.
#
# This file is part of Perses.
#
# Perses is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation; either version 3, or (at your option) any later version.
#
# Perses is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.

set -o errexit
set -o nounset
set -o pipefail

readonly SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
source "${SCRIPT_DIR}/constants.sh" || exit 1

readonly SPOTBUGS_VERSION="${SPOTBUGS_VERSION:-4.10.3}"
readonly PERSES_TOOLS_DIR="${PERSES_TOOLS_DIR:-${HOME}/.perses/tools}"
readonly SPOTBUGS_HOME="${SPOTBUGS_HOME:-${PERSES_TOOLS_DIR}/spotbugs-${SPOTBUGS_VERSION}}"
readonly SPOTBUGS_ARCHIVE="spotbugs-${SPOTBUGS_VERSION}.tgz"
readonly SPOTBUGS_URL="https://github.com/spotbugs/spotbugs/releases/download/${SPOTBUGS_VERSION}/${SPOTBUGS_ARCHIVE}"
readonly PERSES_DEPLOY_JAR="${WORKSPACE_ROOT}/bazel-bin/src/org/perses/perses_deploy.jar"
readonly SPOTBUGS_EXCLUDE_FILE="${SCRIPT_DIR}/spotbugs_exclude.xml"
readonly SPOTBUGS_REPORT_FILE="$(mktemp)"
readonly SPOTBUGS_ERROR_LOG="$(mktemp)"

function cleanup() {
  rm -f "${SPOTBUGS_REPORT_FILE}" "${SPOTBUGS_ERROR_LOG}"
}
trap cleanup EXIT

function download_file() {
  local url="$1"
  local output_file="$2"

  if command -v curl &> /dev/null; then
    curl --fail --location --show-error --silent --retry 3 --output "${output_file}" "${url}"
  elif command -v wget &> /dev/null; then
    wget --output-document "${output_file}" "${url}"
  else
    python3 - "${url}" "${output_file}" <<'PY'
import sys
import urllib.request

url = sys.argv[1]
output_file = sys.argv[2]
urllib.request.urlretrieve(url, output_file)
PY
  fi
}

function ensure_spotbugs() {
  if [[ -x "${SPOTBUGS_HOME}/bin/spotbugs" ]]; then
    return
  fi

  mkdir -p "${PERSES_TOOLS_DIR}"
  local archive_path="${PERSES_TOOLS_DIR}/${SPOTBUGS_ARCHIVE}"
  if [[ ! -f "${archive_path}" ]]; then
    echo "Downloading SpotBugs ${SPOTBUGS_VERSION} to ${archive_path}"
    download_file "${SPOTBUGS_URL}" "${archive_path}"
  fi

  echo "Extracting SpotBugs ${SPOTBUGS_VERSION} to ${PERSES_TOOLS_DIR}"
  tar -xzf "${archive_path}" -C "${PERSES_TOOLS_DIR}"
}

ensure_spotbugs

bazelisk build //src/org/perses:perses_deploy.jar

"${SPOTBUGS_HOME}/bin/spotbugs" \
  -textui \
  -maxHeap 4096 \
  -effort:default \
  -medium \
  -exclude "${SPOTBUGS_EXCLUDE_FILE}" \
  -onlyAnalyze "org.perses.*" \
  -xml:withMessages \
  -output "${SPOTBUGS_REPORT_FILE}" \
  "${PERSES_DEPLOY_JAR}" \
  2> "${SPOTBUGS_ERROR_LOG}"

python3 - "${SPOTBUGS_REPORT_FILE}" "${SPOTBUGS_ERROR_LOG}" <<'PY'
import sys
import xml.etree.ElementTree as ET

report_file = sys.argv[1]
error_log = sys.argv[2]
bugs = ET.parse(report_file).getroot().findall("BugInstance")
if not bugs:
    sys.exit(0)

print("SpotBugs found new warnings in perses_deploy.jar:", file=sys.stderr)
for bug in bugs:
    bug_type = bug.get("type", "unknown")
    category = bug.get("category", "unknown")
    class_element = bug.find("Class")
    source_line = bug.find("SourceLine")
    class_name = class_element.get("classname", "unknown") if class_element is not None else "unknown"
    source_path = source_line.get("sourcepath", "") if source_line is not None else ""
    start_line = source_line.get("start", "") if source_line is not None else ""
    location = f"{source_path}:{start_line}" if source_path and start_line else class_name
    print(f"  {bug_type} ({category}) {location}", file=sys.stderr)
print(file=sys.stderr)
print("SpotBugs stderr:", file=sys.stderr)
with open(error_log, encoding="utf-8") as file:
    sys.stderr.write(file.read())
sys.exit(1)
PY
