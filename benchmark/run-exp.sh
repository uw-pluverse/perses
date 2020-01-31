#!/usr/bin/env bash

set -o pipefail
set -o nounset

if [[ $# != 3 ]] ; then 
  echo "Usage: $0 <exp name> <bug folder> <reduction cmd>"
  exit 1
fi

readonly EXP_NAME=$1
readonly BUG_FOLDER="$(pwd)/$2"
readonly REDUCTION_CMD=$3

readonly SOURCE_NAME="small.c"
readonly TEST_SCRIPT_NAME="r.sh"
readonly SOURCE_FILE="$BUG_FOLDER/${SOURCE_NAME}"
readonly TEST_SCRIPT="$BUG_FOLDER/${TEST_SCRIPT_NAME}"

readonly EXP_FOLDER="$BUG_FOLDER/exp-${EXP_NAME}"
mkdir -p ${EXP_FOLDER}

cp $SOURCE_FILE ${EXP_FOLDER}/
cp $TEST_SCRIPT ${EXP_FOLDER}/


cd ${EXP_FOLDER}

if ! ./${TEST_SCRIPT_NAME} &> /dev/null ; then 
  echo "The initial test failed"
  exit 1
fi

$REDUCTION_CMD --test-script ./$TEST_SCRIPT_NAME --input-file $SOURCE_NAME &> log.txt
