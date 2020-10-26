#!/usr/bin/env python3

import argparse
import json
import os
import subprocess
import tempfile
from datetime import datetime
from dataclasses import dataclass
from typing import List, Dict

__location__ = os.path.realpath(
    os.path.join(os.getcwd(), os.path.dirname(__file__)))

def parse_arguments():
    parser = argparse.ArgumentParser(description="Runs the benchmark and output results in JSON")
    parser.add_argument("-s", "--subjects", nargs='+', default=[], help="Benchmark with specified bench(es)")
    parser.add_argument("-i", "--iterations", type=int, default=1, help="Run bench set for the number of times specified")
    parser.add_argument("--silent", action="store_true", default=False, help="Writes nothing to stdout")
    parser.add_argument("-ss", "--show-subprocess", action="store_true", default=False, help="Show all pipe stdout and stderr from reducers")
    parser.add_argument("-r", "--reducers", nargs='+', default=[], help="Specify reducers for benchmarking.")
    parser.add_argument("-lr", "--list-reducers", action="store_true", default=False, help="List current available reducers")
    parser.add_argument("-mp", "--memory-profiler", action="store_true", default=False, help="Enable Perses memory profiler")
    return parser.parse_args()

@dataclass(frozen=True)
class Parameter:
    # Default field values
    benchmark_target: List[str]
    iterations: int
    silent: bool
    show_subprocess: bool
    reducers: List[str]
    list_reducers: bool
    memory_profiler: bool

    def __post_init__(self):
        if self.list_reducers:
            available_reducers = '\n'.join(list(REDUCERS.keys()))
            print(f"Current available reducers include : \n{available_reducers}")
            exit(1)

    def validate(self):
        # validate parameters
        # benchmark_target
        if self.benchmark_target == []:
            raise Exception('Error: No subjects')
        for bench_name in self.benchmark_target:
            folder_path = os.path.join(__location__, bench_name)
            if not os.path.exists(folder_path):
                raise Exception(f'Error: Folder path not found: {folder_path}')
        # iterations
        if self.iterations < 1:
            raise Exception('Error: Invalid ITERATIONS value')
        # reducers
        if self.reducers == []:
            raise Exception('Error: No reducers')
        if len(self.reducers) != len(set(self.reducers)):
            raise Exception('Error: Duplicated reducers')
        for reducer in self.reducers:
            if reducer not in REDUCERS:
                raise Exception(f'Error: Unknown reducer: {reducer}')

INSTALLS = {
        "perses": os.path.join(__location__, "binaries", "update_perses.sh"),
        "creduce": os.path.join(__location__, "binaries", "update_creduce.sh"),
        "chisel": os.path.join(__location__, "binaries", "update_chisel.sh"),
}

REDUCERS = {
        "perses": os.path.join(__location__, "binaries", "run_perses.sh"),
        "hdd": os.path.join(__location__, "binaries", "run_hdd.sh"),
        "perses-fix": os.path.join(__location__, "binaries", "run_perses_fix.sh"),
        "hdd-fix": os.path.join(__location__, "binaries", "run_hdd_fix.sh"),
        "creduce": os.path.join(__location__, "binaries", "run_creduce.sh"),
        "chisel": os.path.join(__location__, "binaries", "run_chisel.sh"),
}


def load_token_counter(parameter_interface):
    print("Loading token counter ...")
    pipe = subprocess.DEVNULL
    if parameter_interface.show_subprocess:
        pipe = None
    subprocess.run(
        [os.path.join(__location__, "binaries", "update_token_counter.sh")],
        check=False,
        stdout=pipe,
        stderr=pipe)

def load_reducers(parameter_interface):
    print("Loading reducer programs ...")
    for reducer in parameter_interface.reducers:
        if reducer in INSTALLS:
            pipe = subprocess.DEVNULL
            if parameter_interface.show_subprocess:
                pipe = None
            subprocess.run(
                [INSTALLS[reducer]],
                check=False,
                stdout=pipe,
                stderr=pipe)
            print(" Reducer: {} loaded".format(reducer))

def extract_info_properties(bench_name: str)->Dict[str, str]:
    info_dict = dict()

    # validate info.properties
    info_properties_path = os.path.join(__location__, bench_name, "info.properties")
    if not os.path.exists(info_properties_path):
        raise Exception('Error: info.properties not found: {}'.format(info_properties_path))

    with open(info_properties_path, 'r') as target_file:
        temp_list = target_file.read().splitlines()
    for entry in temp_list:
        buf = entry.split('=')
        info_dict[buf[0]] = buf[1]

    # validate source file & script file
    if "source_file" not in info_dict:
        raise Exception('Error: No source_file found in info.properties')
    if "script_file" not in info_dict:
        raise Exception('Error: No script_file found in info.properties')
    source_file_path = os.path.join(__location__, bench_name, info_dict["source_file"])
    if not os.path.exists(source_file_path):
        raise Exception('Error: source_file not found: {}'.format(source_file_path))
    info_dict["source_file_path"] = source_file_path

    script_file_path = os.path.join(__location__, bench_name, info_dict["script_file"])
    if not os.path.exists(script_file_path):
        raise Exception('Error: script_file not found: {}'.format(script_file_path))
    info_dict["script_file_path"] = script_file_path

    return info_dict

def count_token(source_file_path):
    try:
        process = subprocess.Popen(
            [os.path.join(__location__, "binaries", "run_token_counter.sh"),
             source_file_path],
            stderr=subprocess.DEVNULL,
            stdout=subprocess.PIPE)
        count = process.communicate()[0]
        return int(count)
    except Exception as err:
        print("Error counting token for " + source_file_path)
        raise err


def environment_udpater(parameter_interface, bench, time):
    # update env var if memory_profiler enabled
    if parameter_interface.memory_profiler:
        new_env = os.environ.copy()
        new_env["PERSES_MEMORY_PROFILER"] = f"{__location__}/tmp_memory_log_{bench}_{time}"
        return new_env
    else:
        return os.environ.copy()

def main():
    # parameter handler
    args = parse_arguments()
    para = Parameter(args.subjects, args.iterations, args.silent, args.show_subprocess, 
            args.reducers, args.list_reducers, args.memory_profiler)
    para.validate()
    print(para)

    time = datetime.now().strftime("%Y_%m_%d_%H%M%S")
    report = dict() #final printable json results
    report["arguments"] = para
    report["timestamp"] = time
    report["environment"] = f"PERSES_EXTRA_FLAGS = {os.environ.get('PERSES_EXTRA_FLAGS')}"

    # install token counter
    load_token_counter(para)

    # install reducer programs
    load_reducers(para)

    # benchmark starts here
    for bench_name in para.benchmark_target:

        # extract enties into a hash table(dictionary)
        info_dict = extract_info_properties(bench_name)
        source_file_path = info_dict["source_file_path"]
        script_file_path = info_dict["script_file_path"]

        # count bench token
        token_count = count_token(source_file_path)
        if bench_name not in report:
            report[bench_name] = dict()
        report[bench_name]["original_token_count"] = token_count
        if not para.silent:
            print(f"Bench {bench_name} has {token_count} original tokens")


        # reduce
        for reducer in para.reducers:
            print("{} in process".format(reducer))
            for iteration in range(para.iterations):
                print(f"*****iteration {iteration}*****")

                # update environment variables
                new_env = environment_udpater(para, bench_name, time)
                
                # create tmp output file
                fd, fname = tempfile.mkstemp()
                os.close(fd)

                pipe = subprocess.DEVNULL
                if para.show_subprocess:
                    pipe = None
                
                subprocess.run(
                    [REDUCERS[reducer],
                     script_file_path,
                     source_file_path,
                     fname],
                    check=False,
                    stdout=pipe,
                    stderr=pipe,
                    env=new_env)

                with open(fname, "r") as output:
                    run_result = output.read().strip().split("\n")
                    if len(run_result) != 7:
                        run_result = ["unknown", "unknown", "unknown", "failed", "failed", "failed", run_result]
                    report[bench_name][f"{reducer}_iter{iteration}"] = dict()
                    report[bench_name][f"{reducer}_iter{iteration}"]["reducer"] = reducer
                    report[bench_name][f"{reducer}_iter{iteration}"]["bench"] = bench_name
                    report[bench_name][f"{reducer}_iter{iteration}"]["query"] = run_result[3]
                    report[bench_name][f"{reducer}_iter{iteration}"]["time"] = run_result[4]
                    report[bench_name][f"{reducer}_iter{iteration}"]["token_remaining"] = run_result[5]
                    report[bench_name][f"{reducer}_iter{iteration}"]["ret_code"] = run_result[6]

                    if not para.silent:
                        print(report[bench_name][f"{reducer}_iter{iteration}"])
                os.remove(fname)

    # print final report to stdout
    if not para.silent:
        json_object = json.dumps(report, indent=4)
        print(json_object)

        report_title = f'tmp_report_{time}.json'
        with open(report_title, 'w') as out_file:
            out_file.write(json_object)

if __name__ == "__main__":
    main()
