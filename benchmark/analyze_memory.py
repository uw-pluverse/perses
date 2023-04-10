#!/usr/bin/env python3
import re
import os
import json
import argparse
from typing import List, Final, Tuple

__location__ = os.path.realpath(
    os.path.join(os.getcwd(), os.path.dirname(__file__)))

# constant index
TIME: Final = 0
TOTAL: Final = -5
USED: Final = -3
SUBJECT: Final = -4
REDUCER: Final = -3
TIMEMARK: Final = -2


def parse_arguments():
    parser = argparse.ArgumentParser(description="Summarize benchmark results")
    parser.add_argument("files", nargs='+', default=[], help="Json and log files should be paired")
    return parser.parse_args()


def extract_entries(lines: List[str], position: int) -> List:
    array = []
    for line in lines:
        if not re.search("(Heap after|Heap before)", line):
            continue
        line = line.split()
        if position == TIME:
            buf = line[position][1:line[position].find(']') - 1]
            number = float(buf)
            array.append(number)
        else:
            buf = line[position][0:line[position].find('K')]
            number = int(buf)
            array.append(number)
    return array


def average_usage(timestamp: List[float], used: List[float]) -> int:
    # calculate average function value
    # average = area under curve / period
    total_usage = 0
    previous_time = timestamp[0]
    previous_usage = used[0]
    l = len(timestamp)
    for i in range(1, l):
        delta_time = timestamp[i] - previous_time
        usage_sum = used[i] + previous_usage
        # trapezoid rule
        total_usage += usage_sum / 2 * delta_time
        previous_time = timestamp[i]
        previous_usage = used[i]

    return int(total_usage / (timestamp[-1] - timestamp[1]))


def average_usage_after_gc(timestamp: List[float], used: List[float]) -> int:
    # calculate average function value
    # average = area under curve / period
    # after gc and before gc are always paired
    # slice out the after gc from list 'used'
    assert len(timestamp) % 2 == 0
    timestamp = timestamp[1::2]
    assert len(used) % 2 == 0
    used = used[1::2]
    assert len(timestamp) == len(used)

    total_usage = 0
    previous_time = timestamp[0]
    previous_usage = used[0]
    l = len(timestamp)
    for i in range(1, l):
        delta_time = timestamp[i] - previous_time
        usage_sum = used[i] + previous_usage
        # trapezoid rule
        total_usage += usage_sum / 2 * delta_time
        previous_time = timestamp[i]
        previous_usage = used[i]

    return int(total_usage / (timestamp[-1] - timestamp[1]))


def get_gc_number(last_line: str) -> int:
    # get the total number GC events
    buf = last_line.split()[1]
    return int(buf[3:-1])


def analyze_json_file(filepath: str, statistics: dict) -> dict:
    # decode filename
    elements = filepath.split('_')
    subject = elements[SUBJECT]
    reducer = elements[REDUCER]
    timemark = elements[TIMEMARK]
    reducer_at_timemark = f"{reducer}@{timemark}"

    # read json file to a map
    with open(filepath) as f:
        json_dict = json.load(f)

    # trim redundant information
    if subject not in json_dict:
        raise Exception(f"Error: File name and content inconsistent: subject. Please check {filepath}")
    json_dict.pop(subject)
    if reducer not in json_dict:
        raise Exception(f"Error: File name and content inconsistent: REDUCER. Please check {filepath}")
    json_dict.pop(reducer)

    # dictionary keys
    KEY_QUERY: Final = "Query"
    KEY_TIME: Final = "Time"
    KEY_TOKEN_REMAINING: Final = "Token_remaining"
    KEY_ITERATION: Final = "Iteration"

    # append any new data to statistics report
    if subject not in statistics:
        statistics[subject] = dict()
    if reducer_at_timemark not in statistics[subject]:
        statistics[subject][reducer_at_timemark] = json_dict
    else:
        # average if existing already
        statistics[subject][reducer_at_timemark][KEY_QUERY] += json_dict[KEY_QUERY]
        statistics[subject][reducer_at_timemark][KEY_QUERY] //= 2
        statistics[subject][reducer_at_timemark][KEY_TIME] += json_dict[KEY_TIME]
        statistics[subject][reducer_at_timemark][KEY_TIME] //= 2
        statistics[subject][reducer_at_timemark][KEY_TOKEN_REMAINING] += json_dict[KEY_TOKEN_REMAINING]
        statistics[subject][reducer_at_timemark][KEY_TOKEN_REMAINING] //= 2
        if statistics[subject][reducer_at_timemark][KEY_ITERATION] < json_dict[KEY_ITERATION]:
            statistics[subject][reducer_at_timemark][KEY_ITERATION] = json_dict[KEY_ITERATION]


def analyze_log_file(filepath: str, statistics: dict):
    # decode filename
    elements = filepath.split('_')
    subject = elements[SUBJECT]
    reducer = elements[REDUCER]
    timemark = elements[TIMEMARK]
    reducer_at_timemark = f"{reducer}@{timemark}"

    # read log file to a list
    with open(filepath) as f:
        lines = f.readlines()

    # extract memory info from log file
    timestamp = extract_entries(lines, TIME)
    total = extract_entries(lines, TOTAL)
    used = extract_entries(lines, USED)
    peak_memory_before_gc = max(used)
    # after gc and before gc are always paired
    # slice out the after gc from list 'used'
    assert len(used) % 2 == 0
    peak_memory_after_gc = max(used[1::2])

    # dictionary keys
    KEY_PEAK_BEFORE_GC: Final = "peak_memory_before_gc"
    KEY_PEAK_AFTER_GC: Final = "peak_memory_after_gc"
    KEY_AVERAGE_MEMORY_USAGE: Final = "average_memory_usage"
    KEY_AVERAGE_MEMORY_USAGE_AFTER_GC: Final = "average_memory_usage_after_gc"
    KEY_HEAP_ACQUIRED: Final = "heap_size_acquired"
    KEY_GC_NUMBER: Final = "gc_number"

    # calculate memory usages and store in map
    log_dict = dict()
    log_dict[KEY_PEAK_BEFORE_GC] = peak_memory_before_gc
    log_dict[KEY_PEAK_AFTER_GC] = peak_memory_after_gc
    log_dict[KEY_AVERAGE_MEMORY_USAGE] = average_usage(timestamp, used)
    log_dict[KEY_AVERAGE_MEMORY_USAGE_AFTER_GC] = average_usage_after_gc(timestamp, used)
    log_dict[KEY_HEAP_ACQUIRED] = total[-1]
    log_dict[KEY_GC_NUMBER] = get_gc_number(lines[-1])

    if "peak_memory_before_gc" not in statistics[subject][reducer_at_timemark]:
        statistics[subject][reducer_at_timemark].update(log_dict)
    else:
        statistics[subject][reducer_at_timemark][KEY_PEAK_BEFORE_GC] += log_dict[KEY_PEAK_BEFORE_GC]
        statistics[subject][reducer_at_timemark][KEY_PEAK_BEFORE_GC] //= 2
        statistics[subject][reducer_at_timemark][KEY_PEAK_AFTER_GC] += log_dict[KEY_PEAK_AFTER_GC]
        statistics[subject][reducer_at_timemark][KEY_PEAK_AFTER_GC] //= 2
        statistics[subject][reducer_at_timemark][KEY_AVERAGE_MEMORY_USAGE] += log_dict[KEY_AVERAGE_MEMORY_USAGE]
        statistics[subject][reducer_at_timemark][KEY_AVERAGE_MEMORY_USAGE] //= 2
        statistics[subject][reducer_at_timemark][KEY_AVERAGE_MEMORY_USAGE_AFTER_GC] += log_dict[KEY_AVERAGE_MEMORY_USAGE_AFTER_GC]
        statistics[subject][reducer_at_timemark][KEY_AVERAGE_MEMORY_USAGE_AFTER_GC] //= 2
        statistics[subject][reducer_at_timemark][KEY_HEAP_ACQUIRED] += log_dict[KEY_HEAP_ACQUIRED]
        statistics[subject][reducer_at_timemark][KEY_HEAP_ACQUIRED] //= 2
        statistics[subject][reducer_at_timemark][KEY_GC_NUMBER] += log_dict[KEY_GC_NUMBER]
        statistics[subject][reducer_at_timemark][KEY_GC_NUMBER] //= 2


def validate_existence(filepath: str):
    if not os.path.exists(filepath):
        raise Exception(f"Error: File not found in path: {filepath}")


def validate_integrity(file_list: List[str]) -> Tuple[dict, list]:
    # set of reducers who should have paired input files
    paired_reducers = {"perses"}

    files_paired = dict()
    files_single = list()

    for file in file_list:
        validate_existence(file)

        # decode file name
        elements = file.split('_')
        reducer = elements[REDUCER]

        if reducer in paired_reducers:
            # reducers expect paired input files
            if file.endswith(".json"):
                files_paired[file] = None
            elif file.endswith(".log"):
                key = file.replace(".log", ".json")
                if key in files_paired:
                    files_paired[key] = file
                else:
                    # no corresponding json file
                    raise Exception(f"Error: Integrity check: No paired json file for: {file}")
            else:
                raise Exception(f"Error: Integrity check: Unsupported file type: {file}")
        else:
            # reducers expect a single input file
            if file.endswith(".json"):
                files_single.append(file)
            else:
                raise Exception(f"Error: Integrity check: Unsupported file type: {file}")

    # check if any json file missing log file
    for key in files_paired:
        if files_paired[key] is None:
            raise Exception(f"Error: Integrity check: No paired log file for: {key}")

    return files_paired, files_single


def main():
    args = parse_arguments()
    statistics = dict()
    files_sorted = sorted(args.files)

    files_paired, files_single = validate_integrity(files_sorted)

    # paired input files
    for file in files_paired:
        analyze_json_file(file, statistics)
        analyze_log_file(files_paired[file], statistics)
    # single input file
    for file in files_single:
        analyze_json_file(file, statistics)

    json_object = json.dumps(statistics, indent=4)
    print(json_object)


if __name__ == "__main__":
    main()
