#!/usr/bin/env python3
import re
import os
import json
import argparse
from typing import List, Final, Tuple, Dict

__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))


def parse_arguments():
    parser = argparse.ArgumentParser(description="Summarize benchmark results (in Byte)")
    parser.add_argument("files", nargs='+', default=[], help="Json and log files should be paired")
    return parser.parse_args()


def extract_entries(lines: List[str]) -> Tuple[List[int], List[int]]:
    # cache samples stores in form: '<timestamp> <size>'
    timestamp = []
    cache = []
    for line in lines:
        line.rstrip()
        t, c = line.split()
        timestamp.append(int(t))
        cache.append(int(c))
    return timestamp, cache


def average_usage(timestamp: List[int], cache: List[int]) -> int:
    # calculate average function value
    # average = area under curve / period
    assert len(timestamp) == len(cache)
    if len(timestamp) == 0:
        return -1
    elif len(timestamp) == 1:
        return cache[0]
    total_usage = 0
    previous_time = timestamp[0]
    previous_usage = cache[0]
    l = len(timestamp)
    for i in range(1, l):
        delta_time = timestamp[i] - previous_time
        usage_sum = cache[i] + previous_usage
        # trapezoid rule
        total_usage += usage_sum / 2 * delta_time
        previous_time = timestamp[i]
        previous_usage = cache[i]

    return int(total_usage / (timestamp[-1] - timestamp[0]))


def average_dict_item(orig_dict: dict, update_dict: dict,key: str):
    orig_dict[key] += update_dict[key]
    orig_dict[key] //= 2


def analyze_json_file(filepath: str, statistics_handle: dict):
    # decode filename
    base = os. path. basename(filepath)
    base = os.path.splitext(base)[0]
    buf, subject, reducer, timemark, iter = base.split('_')
    reducer_t = f"{reducer}@{timemark}"

    # read json file to a map
    with open(filepath) as f:
        json_dict = json.load(f)

    # trim redundant information
    if subject != json_dict['subject']:
        raise Exception(f"Error: File name and content inconsistent: Subject. Please check {filepath}")
    json_dict.pop('subject')
    if reducer != json_dict['Reducer']:
        raise Exception(f"Error: File name and content inconsistent: REDUCER. Please check {filepath}")
    json_dict.pop('Reducer')

    # dictionary keys
    QUERY: Final = "Query"
    TIME: Final = "Time"
    TOKEN_R: Final = "Token_remaining"

    # append any new data to statistics report
    if subject not in statistics_handle:
        statistics_handle[subject] = dict()
    if reducer_t not in statistics_handle[subject]:
        statistics_handle[subject][reducer_t] = json_dict
    else:
        # average if existing already
        sub_dict = statistics_handle[subject][reducer_t]
        average_dict_item(sub_dict, json_dict, QUERY)
        average_dict_item(sub_dict, json_dict, TIME)
        average_dict_item(sub_dict, json_dict, TOKEN_R)


def analyze_log_file(filepath: str, statistics: dict):
    # decode filename
    base = os. path. basename(filepath)
    base = os.path.splitext(base)[0]
    buf, subject, reducer, timemark, iter = base.split('_')
    reducer_t = f"{reducer}@{timemark}"

    # read log file to a list
    with open(filepath) as f:
        lines = f.readlines()

    # extract memory info from log file
    timestamp, cache = extract_entries(lines)

    # dictionary keys
    PEAK: Final = "peak_cache_size"
    AVG: Final = "average_memory_usage"
    NUM_SAMPLES: Final = "number_of_samples"

    # calculate memory usages and store in map
    log_dict = dict()
    log_dict[PEAK] = max(cache)
    log_dict[AVG] = average_usage(timestamp, cache)
    log_dict[NUM_SAMPLES] = len(lines)

    if PEAK not in statistics[subject][reducer_t]:
        statistics[subject][reducer_t].update(log_dict)
    else:
        sub_dict = statistics[subject][reducer_t]
        average_dict_item(sub_dict, log_dict, PEAK)
        average_dict_item(sub_dict, log_dict, AVG)
        average_dict_item(sub_dict, log_dict, NUM_SAMPLES)


def validate_existence(filepath: str):
    if not os.path.exists(filepath):
        raise Exception(f"Error: File not found in path: {filepath}")


def pair_files(file_list: List[str]) -> Dict[str, str]:
    """result json and profiling log file should appear in a pair"""
    file_list.sort()
    files_paired = dict()
    for file in file_list:
        if file.endswith(".json"):
            validate_existence(file)
            log_file = file.replace(".json", ".log")
            validate_existence(log_file)
            files_paired[file] = log_file
    return files_paired

def print_json_as_csv(statistics):
    print("Subject,Entry_peak_cache,Average_cache,Entry_environment")

    for subject in statistics.keys():
        entries = statistics[subject]
        for key in entries.keys():
            entry_environment = entries[key]["Environment"].replace("--query-cache-type ", "")
            entry_peak_cache = entries[key]["peak_cache_size"]
            average_cache = entries[key]["average_memory_usage"]
            print(f"{subject},{entry_peak_cache},{average_cache},{entry_environment}")

def main():
    args = parse_arguments()
    statistics = dict()

    files_paired = pair_files(args.files)

    # paired input files
    for json_file, log_file in files_paired.items():
        analyze_json_file(json_file, statistics)
        analyze_log_file(log_file, statistics)

    json_object = json.dumps(statistics, indent=4)
    print(json_object)

    print_json_as_csv(statistics=statistics)


if __name__ == "__main__":
    main()
