#!/usr/bin/env python3

import argparse
import json
import re
import os
import subprocess
import tempfile
from datetime import datetime
from dataclasses import dataclass
from typing import List, Dict, Tuple

__location__ = os.path.realpath(
    os.path.join(os.getcwd(), os.path.dirname(__file__)))

INSTALLS = {
    "perses": os.path.join(__location__, "binaries", "update_perses.sh"),
    "hdd": os.path.join(__location__, "binaries", "update_perses.sh"),
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

def parse_arguments():
    parser = argparse.ArgumentParser(description="Runs the benchmark and output results in JSON")
    parser.add_argument("-s", "--subjects", nargs='+', default=[], help="Benchmark with specified subject(s)")
    parser.add_argument("-r", "--reducers", nargs='+', default=[], help="Specify reducers for benchmarking.")
    parser.add_argument("-m", "--monitor-interval",
                        help="Cache consumption monitor interval in millisecond. Default is 5 min (5 * 60 * 1000)")
    parser.add_argument("-ss", "--show-subprocess", action="store_true", default=False,
                        help="Show all pipe stdout and stderr from reducers")
    parser.add_argument("-o", "--output_dir", type=str,
                        help="output folder")
    parser.add_argument("-i", "--iterations", type=int, default=1,
                        help="Repeat the benchmark for the number of times specified")
    return parser.parse_args()


@dataclass
class Parameter:
    benchmark_target: List[str]
    reducers: List[str]
    show_subprocess: bool
    iterations: int
    monitor_interval: int
    output_dir: str = None

    def __post_init__(self):
        self.validate()
        # set output dir
        if self.output_dir is None:
            general_result_dir = "benchmark_memory_results"
            general_result_subdir = f"benchmark_{datetime.now().strftime('%Y%m%d-%H%M%S')}"
            self.output_dir = os.path.join(__location__, general_result_dir, general_result_subdir)
            os.makedirs(self.output_dir, exist_ok=True)
        else:
            self.output_dir = os.path.abspath(self.output_dir)
            if not os.path.exists(self.output_dir):
                os.makedirs(self.output_dir)

    def validate(self):
        # validate parameters
        # benchmark_target
        if not self.benchmark_target:
            raise Exception('Error: No Subject(s)')
        for subject_name in self.benchmark_target:
            folder_path = os.path.join(__location__, subject_name)
            if not os.path.exists(folder_path):
                raise Exception(f'Error: Folder path not found: {folder_path}')
        # reducers
        if not self.reducers:
            raise Exception('Error: No reducers detected')
        if len(self.reducers) != len(set(self.reducers)):
            raise Exception('Error: Duplicated reducers detected')
        for reducer in self.reducers:
            if reducer not in REDUCERS:
                raise Exception(f'Error: Unknown reducer: {reducer}')
        # iterations
        if self.iterations < 1:
            raise Exception('Error: Invalid ITERATIONS value')


def load_token_counter(subprocess_flag: bool):
    print("Loading token counter ...")
    pipe = None if subprocess_flag else subprocess.DEVNULL
    subprocess.run(
        [os.path.join(__location__, "binaries", "update_token_counter.sh")],
        check=False,
        stdout=pipe,
        stderr=pipe,
        )


def load_reducers(reducer_list: List[str], subprocess_flag: bool):
    print("Loading reducer programs ...")
    for reducer in reducer_list:
        if reducer in INSTALLS:
            pipe = None if subprocess_flag else subprocess.DEVNULL
            subprocess.run(
                [INSTALLS[reducer]],
                check=False,
                stdout=pipe,
                stderr=pipe)
            print(" Reducer: {} loaded".format(reducer))


def extract_info_properties(subject_name: str) -> Tuple[str, str]:
    """Extract script file and source file from a subject folder"""
    info_dict = dict()

    # validate info.properties path
    info_properties_path = os.path.join(__location__, subject_name, "info.properties")
    if not os.path.exists(info_properties_path):
        raise Exception(f'Error: info.properties not found: {info_properties_path}')

    with open(info_properties_path, 'r') as target_file:
        temp_list = target_file.read().splitlines()
    for entry in temp_list:
        buf = entry.split('=')
        info_dict[buf[0]] = buf[1]

    # validate source file & script file path
    if "source_file" not in info_dict:
        raise Exception('Error: No source_file found in info.properties')
    if "script_file" not in info_dict:
        raise Exception('Error: No script_file found in info.properties')

    source_file_path = os.path.join(__location__, subject_name, info_dict["source_file"])
    script_file_path = os.path.join(__location__, subject_name, info_dict["script_file"])

    if not os.path.exists(source_file_path):
        raise Exception('Error: source_file not found: {}'.format(source_file_path))
    if not os.path.exists(script_file_path):
        raise Exception('Error: script_file not found: {}'.format(script_file_path))

    return source_file_path, script_file_path


def count_token(source_file_path: str) -> int:
    try:
        token_counter_sh = os.path.join(__location__, "binaries", "run_token_counter.sh")
        count = subprocess.check_output(
            [token_counter_sh, source_file_path], 
            stderr=subprocess.STDOUT)
        return int(count)
    except Exception as err:
        print("Error counting token for " + source_file_path)
        raise err


def filename_generator(subject: str, reducer: str, iteration: int, timemark: str) -> Tuple[str, str]:
    # generate proper names for report (and memory log if applicable)
    subject = os.path.basename(subject)
    filename_report = f"tmp_{subject}_{reducer}_{timemark}_itr{iteration}.json"
    filename_log = f"tmp_{subject}_{reducer}_{timemark}_itr{iteration}.log"

    return filename_report, filename_log


def environment_updater(parameter, filename_log: str) -> tuple:
    # update environment variable as per command line argument
    output_dir = parameter.output_dir

    enviroment = os.environ.copy()
    root_directory = os.path.dirname(__location__)
    if not os.path.exists(f'{root_directory}/third_party/memory_measurer/object-explorer.jar'):
        raise Exception(f'ERROR: Not found: {root_directory}/third_party/memory_measurer/object-explorer.jar')

    jvm_caching_flag = f'-javaagent:{root_directory}/third_party/memory_measurer/object-explorer.jar --add-opens java.base/jdk.internal.ref=ALL-UNNAMED'
    jvm_flags = os.environ.get('JVM_FLAGS')
    if jvm_flags:
        enviroment['JVM_FLAGS'] = f'{jvm_flags} {jvm_caching_flag}'
    else:
        enviroment['JVM_FLAGS'] = f'{jvm_caching_flag}'

    constant_caching_flag = f''
    perses_caching_flag = f'--profile-query-cache-memory {os.path.join(output_dir, filename_log)}'
    perses_flags = os.environ.get('PERSES_FLAGS')
    if perses_flags:
        enviroment['PERSES_FLAGS'] = f'{perses_flags} {perses_caching_flag}'
    else:
        enviroment['PERSES_FLAGS'] = f'{perses_caching_flag}'

    if parameter.monitor_interval:
        enviroment['PERSES_CACHE_MEMORY_PROFILING_TIME_INTERVAL'] = f'{parameter.monitor_interval}'

    return enviroment, perses_flags


def report_generator(subject, reducer, reducer_flags, token_count, iteration, run_result: list):
    """Report initialization"""
    report = dict()
    report['Subject'] = subject
    report['Reducer'] = reducer
    report["Environment"] = reducer_flags
    report["Origin token count"] = token_count
    report["Iteration"] = iteration
    report["Query"] = int(run_result[3])
    report["Time"] = int(run_result[4])
    report["Token_remaining"] = int(run_result[5])
    report["Ret_code"] = int(run_result[6])
    return report


def output_manager(output_dir: str, filename_report: str, report: dict):
    """Manage sub-directory creation and output file"""
    output_filepath = os.path.join(output_dir, filename_report)
    # store benchmark to json file
    json_object = json.dumps(report, indent=4)
    print(json_object)
    with open(output_filepath, 'w') as out_file:
        out_file.write(json_object)
    print(f'Output path: {output_filepath}')


def main():
    # parameter handler
    args = parse_arguments()
    parameter = Parameter(
        args.subjects,
        args.reducers,
        args.show_subprocess,
        args.iterations,
        args.monitor_interval,
        args.output_dir
    )
    print(parameter)

    # install token counter
    load_token_counter(parameter.show_subprocess)

    # install reducer programs
    load_reducers(parameter.reducers, parameter.show_subprocess)

    # benchmark starts here
    for subject_name in parameter.benchmark_target:
        # prettify subject name
        if subject_name[-1] == "/":
            subject_name = subject_name[:-1]

        # extract test subject information (source file & test script)
        source_file_path, script_file_path = extract_info_properties(subject_name)

        # count subject tokens
        token_count = count_token(source_file_path)
        print(f"Subject {subject_name} has {token_count} original tokens")

        # reduction
        for reducer in parameter.reducers:
            print(f"{reducer} in process")
            # unique time mark distinguishes different settings
            time = datetime.now().strftime("%Y%m%d-%H%M%S")

            for iteration in range(parameter.iterations):
                print(f"***** Iteration: {iteration} *****")
                # create report filename (and log filename if applicable)
                filename_report, filename_log = filename_generator(subject_name, reducer, iteration, time)
                # setup environment variables for subprocess
                environment, reducer_flags = environment_updater(parameter, filename_log)

                # tmp file for reducer's output
                fd, fname = tempfile.mkstemp()
                os.close(fd)

                # run reduce scripts
                pipe = None if parameter.show_subprocess else subprocess.DEVNULL

                subprocess.run(
                    [REDUCERS[reducer],
                     script_file_path,
                     source_file_path,
                     parameter.output_dir,
                     fname],
                    check=False,
                    stdout=pipe,
                    stderr=pipe,
                    env=environment)

                # retrieve reduction results
                with open(fname, "r") as output:
                    run_result = output.read().strip().split("\n")
                    if len(run_result) != 7:
                        run_result = ["unknown", "unknown", "unknown", "failed", "failed", "failed", run_result]
                os.remove(fname)

                report = report_generator(subject_name, reducer, reducer_flags, token_count, iteration, run_result)
                output_manager(parameter.output_dir, filename_report, report)


if __name__ == "__main__":
    main()
