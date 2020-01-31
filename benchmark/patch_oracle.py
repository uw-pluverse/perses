#!/usr/bin/env python3

import os
import subprocess
import sys

patch = """
readonly REDUCTION_STAT_FILE=${REDUCTION_STAT_FILE:-""}
if [[ -n "${REDUCTION_STAT_FILE}" ]] ; then
#  echo "------------------------------------------------------------------------------" >> "/tmp/reductionstatfile.txt"
#  echo "written reduction stat file '${REDUCTION_STAT_FILE}' " >> "/tmp/reductionstatfile.txt"
#  echo "------------------------------------------------------------------------------" >> "/tmp/reductionstatfile.txt"
  date +%Y%m%d_%H%M%S_%Z >> "${REDUCTION_STAT_FILE}"
fi
"""

def main(file):
    subprocess.run(["git", "checkout", file], check=False)
    
    newFile = []
    with open(file) as f:
        lines = f.readlines()
        if len(lines) > 0 and str(lines[0]).startswith("#!"):
            newFile.append(lines[0])
            lines = lines[1:]
        newFile.append(patch)
        newFile.extend(lines)
    for line in newFile:
        print(line, end="")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Need arguments for file to patch")
    else:
        main(sys.argv[1])
