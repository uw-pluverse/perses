#!/usr/bin/env bash

set -o nounset

readonly CAMPAIGN_ROOT_DIR="kitten/temp_testing_campaigns"

readonly FINDING_FOLDER="${CAMPAIGN_ROOT_DIR}/default_finding_folder_rust"
readonly PROCESSING_FOLDER="${CAMPAIGN_ROOT_DIR}/default_processing_folder_rust"
readonly DUPLICATE_FOLDER="${CAMPAIGN_ROOT_DIR}/default_duplicate_folder_rust"

mkdir -p "${CAMPAIGN_ROOT_DIR}"
mkdir -p "${FINDING_FOLDER}"
mkdir -p "${PROCESSING_FOLDER}"
mkdir -p "${DUPLICATE_FOLDER}"

readonly LOG_FILE="${CAMPAIGN_ROOT_DIR}/testing-process.log"
readonly REPORTED_FOLDER="kitten/reported_bugs/rust"
