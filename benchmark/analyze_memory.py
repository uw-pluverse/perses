#!/usr/bin/env python3

import argparse
import json

from typing import List


def parse_arguments():
    parser = argparse.ArgumentParser(description="Analyse memory log file produced from jstat")
    parser.add_argument("files", nargs='+', default=[], help="List of file(s) to be analyzed")
    return parser.parse_args()


def read_file(file_name: str) -> List[str]:
    with open(file_name) as f:
        lines = f.read()
    return lines.split('\n')


def get_average_heap_usage(data: List[str]) -> int:
    heap = []
    for line in data:
        if 'Timestamp' in line:
            continue
        data = line.split()
        heap.append(int(float(data[3])+float(data[9])))

    sample_quantity = int(len(heap)*0.3)
    samples = heap[sample_quantity::]

    return int(sum(samples)/len(samples))


def main():
    report = dict()

    for file in parse_arguments().files:
        report[file] = dict()

        lines = read_file(file)

        average_usage = get_average_heap_usage(lines)

        report[file]['average_heap_usage (kB)'] = average_usage

    json_object = json.dumps(report, indent=4)
    print(json_object)


if __name__ == "__main__":
    main()
