#!/usr/bin/env python3

import argparse
import json
import os
import subprocess
import tempfile
from dataclasses import dataclass, field
from typing import List, Dict

__location__ = os.path.realpath(
    os.path.join(os.getcwd(), os.path.dirname(__file__)))

@dataclass
class Parameter:
    """Variable field"""
    benchmark_target: List[str] = field(default_factory=list)
    iterations: int = 1
    silent: bool = False
    show_subprocess: bool = False
    results: Dict[str,dict] = field(default_factory=dict)


INSTALLS = [
    ("perses", os.path.join(__location__, "binaries", "update_perses.sh")),
    ("creduce", os.path.join(__location__, "binaries", "update_creduce.sh")),
    ("chisel", os.path.join(__location__, "binaries", "update_chisel.sh")),
#    ("pardis", os.path.join(__location__, "binaries", "update_pardis.sh"))
]

REDUCERS = [
    ("perses", os.path.join(__location__, "binaries", "run_perses.sh")),
    ("hdd", os.path.join(__location__, "binaries", "run_hdd.sh")),
    ("perses-fix", os.path.join(__location__, "binaries", "run_perses_fix.sh")),
    ("hdd-fix", os.path.join(__location__, "binaries", "run_hdd_fix.sh")),
    ("creduce", os.path.join(__location__, "binaries", "run_creduce.sh")),
    ("chisel", os.path.join(__location__, "binaries", "run_chisel.sh")),
#    ("pardis", os.path.join(__location__, "binaries", "run_pardis.sh"))
]


def parse_arguments():
    parser = argparse.ArgumentParser(description="Runs the benchmark and output results in JSON")
    parser.add_argument("-s", "--subjects", nargs='+', metavar='BENCH_FOLDER', help="Benchmark with specified bench(es)")
    parser.add_argument("-i", "--iterations", type=int, help="Run bench set for the number of times specified")
    parser.add_argument("--silent", action="store_true", help="Writes nothing to stdout")
    parser.add_argument("-ss", "--show_subprocess", action="store_true", help="Show all pipe stdout and stderr from reducers")
    return parser.parse_args()

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
    for reducer_name, updater_path in INSTALLS:
        pipe = subprocess.DEVNULL
        if parameter_interface.show_subprocess:
            pipe = None
        subprocess.run(
            [updater_path],
            check=False,
            stdout=pipe,
            stderr=pipe)
        print("Reducer: {} loaded".format(reducer_name))

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


def main():

    # data class init
    para = Parameter()

    # arguments facotry
    args = parse_arguments()
    if args.subjects:
        para.benchmark_target = args.subjects
        #validate bench folder
        for bench_name in para.benchmark_target:
            folder_path = os.path.join(__location__, bench_name)
            if not os.path.exists(folder_path):
                raise Exception('Error: folder path not found: {}'.format(folder_path))
    if args.iterations:
        para.iterations = args.iterations
    if args.silent:
        para.silent = True
        para.silent_subprocess = True
    if args.show_subprocess:
        para.show_subprocess = True

    # install token counter
    load_token_counter(para)

    # install reducer programs
    load_reducers(para)
    
    # benchmark
    for iteration in range(para.iterations):
        print("=====Iteration {}=====".format(iteration+1))

        for bench_name in para.benchmark_target:

            # validate info.properties
            info_properties_path = os.path.join(__location__, bench_name, "info.properties")
            if not os.path.exists(info_properties_path):
                raise Exception('Error: info.properties not found: {}'.format(info_properties_path))

            # validate source file & script file
            with open(info_properties_path, 'r') as target_file:
                source_file = target_file.readline().rstrip().split('=')[1]
                script_file = target_file.readline().rstrip().split('=')[1]
            source_file_path = os.path.join(__location__, bench_name, source_file)
            if not os.path.exists(source_file_path):
                raise Exception('Error: source_file not found: {}'.format(source_file_path))
            script_file_path = os.path.join(__location__, bench_name, script_file)
            if not os.path.exists(script_file_path):
                raise Exception('Error: script_file not found: {}'.format(script_file_path))

            # count bench token
            token_count = count_token(source_file_path)
            if bench_name not in para.results:
                para.results[bench_name] = dict()

            para.results[bench_name]["original_token_count"] = token_count
            if not para.silent:
                print("Bench {} has {} original tokens".format(bench_name, token_count))

            # reduce
            for reducer_name, reducer_path in REDUCERS:
                fd, fname = tempfile.mkstemp()
                os.close(fd)
                pipe = subprocess.DEVNULL
                if para.show_subprocess:
                    pipe = None

                subprocess.run(
                    [reducer_path,
                     script_file_path,
                     source_file_path,
                     fname],
                    check=False,
                    stdout=pipe,
                    stderr=pipe)

                with open(fname, "r") as output:
                    run_result = output.read().strip().split("\n")
                    if len(run_result) != 7:
                        run_result = ["unknown", "unknown", "unknown", "failed", "failed", "failed", run_result]
                    para.results[bench_name][reducer_name] = dict()
                    para.results[bench_name][reducer_name]["reducer"] = reducer_name
                    para.results[bench_name][reducer_name]["bench"] = bench_name
                    para.results[bench_name][reducer_name]["query"] = run_result[3]
                    para.results[bench_name][reducer_name]["time"] = run_result[4]
                    para.results[bench_name][reducer_name]["reduced_token"] = run_result[5]
                    para.results[bench_name][reducer_name]["ret_code"] = run_result[6]
                    if not para.silent:
                        print("Reducer:{} Bench:{} Query:{} Time(s):{} Token left:{} Ret code:{}".format(reducer_name, bench_name, run_result[3], run_result[4], run_result[5], run_result[6]), flush=True)
                os.remove(fname)

    #print final report
    if not para.silent:
        print(json.dumps(para.results, indent=2))


if __name__ == "__main__":
    main()
