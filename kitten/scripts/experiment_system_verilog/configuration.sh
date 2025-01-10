#!/usr/bin/env bash

set -o nounset

readonly LANG="SYSVERILOG"

readonly CAMPAIGN_ROOT_DIR="kitten/temp_testing_campaigns"

readonly FINDING_FOLDER="${CAMPAIGN_ROOT_DIR}/default_finding_folder_${LANG}"
readonly PROCESSING_FOLDER="${CAMPAIGN_ROOT_DIR}/default_processing_folder_${LANG}"
readonly DUPLICATE_FOLDER="${CAMPAIGN_ROOT_DIR}/default_duplicate_folder_${LANG}"

mkdir -p "${CAMPAIGN_ROOT_DIR}"
mkdir -p "${FINDING_FOLDER}"
mkdir -p "${PROCESSING_FOLDER}"
mkdir -p "${DUPLICATE_FOLDER}"

readonly DATE_TIME=$(date +'%Y_%m_%d_%H_%M')
readonly LOG_FILE="${CAMPAIGN_ROOT_DIR}/testing-process-${LANG}-${DATE_TIME}.log"
readonly REPORTED_FOLDER="kitten/reported_bugs/${LANG}"
