#!/usr/bin/env python3

import argparse
import atexit
import json
import os
import signal
import subprocess
import sys
import tempfile

__location__ = os.path.realpath(
    os.path.join(os.getcwd(), os.path.dirname(__file__)))

'''
BENCHMARK_ALL = [
    ('clang-22382', 'r.sh', 'small.c'),
    ('clang-22704', 'r.sh', 'small.c'),
    ('clang-23309', 'r.sh', 'small.c'),
    ('clang-23353', 'r.sh', 'small.c'),
    ('clang-25900', 'r.sh', 'small.c'),
    ('clang-26350', 'r.sh', 'small.c'),
    ('clang-26760', 'r.sh', 'small.c'),
    ('clang-27137', 'r.sh', 'small.c'),
    ('clang-27747', 'r.sh', 'small.c'),
    ('clang-31259', 'r.sh', 'small.c'),
    ('gcc-59903', 'r.sh', 'small.c'),
    ('gcc-60116', 'r.sh', 'small.c'),
    ('gcc-61383', 'r.sh', 'small.c'),
    ('gcc-61917', 'r.sh', 'small.c'),
    ('gcc-64990', 'r.sh', 'small.c'),
    ('gcc-65383', 'r.sh', 'small.c'),
    ('gcc-66186', 'r.sh', 'small.c'),
    ('gcc-66375', 'r.sh', 'small.c'),
    ('gcc-70127', 'r.sh', 'small.c'),
    ('gcc-70586', 'r.sh', 'small.c'),
    ('gcc-71626', 'r.sh', 'small.c')]

BENCHMARK_SMALL = [
    ('toys/parentheses', 'r.sh', 't.c'),
    ('toys/delta_1', 'r.sh', 't.c')#,
#    ('gcc-71626', 'r.sh', 'small.c')
]
'''

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

#variable initialization field
benchmark_target = []
output_latex = None
silent = False
silent_subprocess = False
iterations = 1

results=dict()


def print_results():
    if not silent:
        print(json.dumps(results, indent=2))

atexit.register(print_results)
signal.signal(signal.SIGALRM, print_results)

def write_file():
    if output_latex:
        with open(output_latex, "w") as output_f:
            output_f.write(json.dumps(results))

atexit.register(write_file)

def count_token(source_file_path):
    try:
        process = subprocess.Popen(
            [os.path.join(__location__, "binaries", "run_token_counter.sh"),
             source_file_path],
            stderr=subprocess.DEVNULL,
            stdout=subprocess.PIPE)
        result = process.communicate()[0]
        return int(result)
    except Exception as err:
        print("Error counting token for " + source_file_path)
        raise err

def main():
    # install token counter
    pipe = None
    if silent_subprocess:
        pipe = subprocess.DEVNULL
    subprocess.run(
        [os.path.join(__location__, "binaries", "update_token_counter.sh")],
        check=False,
        stdout=pipe,
        stderr=pipe)
    # install programs
    for reducer_name, updater_path in INSTALLS:
        pipe = None
        if silent_subprocess:
            pipe = subprocess.DEVNULL
        subprocess.run(
            [updater_path],
            check=False,
            stdout=pipe,
            stderr=pipe)
    if not silent:
        print("reducer", "bench", "query", "time", "token", "code")

    # run programs
    for iteration in range(iterations):
        print("Iteration {}".format(iteration+1))

        for bench_name in benchmark_target:
            #validate info.propties
            info_properties_path = os.path.join(folder_path, "info.properties")
            if not os.path.exists(info_properties_path):
                raise Exception('Error: info.properties not found: {}'.format(info_properties_path))
            with open(info_properties_path, 'r') as f:
                source_file = f.readline().rstrip().split('=')[1]
                script_file = f.readline().rstrip().split('=')[1]

            #validate source file & script file
            source_file_path = os.path.join(__location__, bench_name, source_file)
            script_file_path = os.path.join(__location__, bench_name, script_file)
            if not os.path.exists(source_file_path):
                raise Exception('Error: source_file not found: {}'.format(source_file_path))
            if not os.path.exists(script_file_path):
                raise Exception('Error: script_file not found: {}'.format(script_file_path))

            # Count bench token count
            token_count = count_token(source_file_path)
            if bench_name not in results:
                results[bench_name] = dict()
            results[bench_name]["original_token_count"] = token_count
            if not silent:
                print(bench_name + " have " + str(token_count) + " original tokens")

            for reducer_name, reducer_path in REDUCERS:
                fd, fname = tempfile.mkstemp()
                os.close(fd)
                pipe = None
                if silent_subprocess:
                    pipe = subprocess.DEVNULL
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
                    results[bench_name][reducer_name] = dict()
                    results[bench_name][reducer_name]["reducer"] = reducer_name
                    results[bench_name][reducer_name]["bench"] = bench_name
                    results[bench_name][reducer_name]["query"] = run_result[3]
                    results[bench_name][reducer_name]["time"] = run_result[4]
                    results[bench_name][reducer_name]["reduced_token"] = run_result[5]
                    results[bench_name][reducer_name]["ret_code"] = run_result[6]
                    if not silent:
                        print(reducer_name, bench_name, run_result[3], run_result[4], run_result[5], run_result[6], flush=True)
                os.remove(fname)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = "Runs the benchmark and output results in JSON")
    # benchmark all or subset. default subset

    '''
    parser.add_argument("--benchmark-subset", "-bs", action="store_true", help="Benchmark with toys")
    parser.add_argument("--benchmark-all", "-ba", action="store_true", help="Benchmark with clang and gcc")
    parser.add_argument("--silent", "-s", action="store_true", help="Writes nothing to stdout")
    parser.add_argument("--silent-subprocess", "-ss", action="store_true", help="Do not pipe the stdout and stderr from the reducers to the benchmark script. Useful if you only want results")
    parser.add_argument("--output", "-o", action="store", help="File where results from the benchmarks are dumped")
    parser.add_argument("--start", action="store", help="Starting index from the list of benchmarks where the benchmark process begins")
    parser.add_argument("--length", action="store", help="Number of benchmarks from the list to run")
    '''

    parser.add_argument("--subjects", nargs='+', help="Benchmark with the subjects provided in a list of file paths")
    parser.add_argument("--iterations", type=int, help="Run each subjects for the number of times specified")
    
    
    
    parsed = parser.parse_args()

    '''
    if parsed.benchmark_subset:
        benchmark_target = BENCHMARK_SMALL
    if parsed.benchmark_all:
        benchmark_target = BENCHMARK_ALL
    if parsed.silent:
        silent = True
        silent_subprocess = True
    if parsed.silent_subprocess:
        silent_subprocess = True
    output_latex = parsed.output
    if parsed.start:
        if str.isdigit(parsed.start):
            benchmark_target = benchmark_target[int(parsed.start):]
        else:
            print("Expect number for start, got: " + parsed.start)
            sys.exit(1)
    if parsed.length:
        if str.isdigit(parsed.length):
            benchmark_target = benchmark_target[:int(parsed.length)]
        else:
            print("Expect number for length, got: " + parsed.length)
            sys.exit(1)
    '''

    if parsed.subjects:
        benchmark_target = parsed.subjects
        for bench_name in benchmark_target:
            folder_path = os.path.join(__location__, bench_name)
            if not os.path.exists(folder_path):
                raise Exception('Error: folder path not found: {}'.format(folder_path))
        print(benchmark_target)

    if parsed.iterations:
        iterations=parsed.iterations
        print(iterations)
    main()
