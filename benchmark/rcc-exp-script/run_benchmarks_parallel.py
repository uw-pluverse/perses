import json
from datetime import datetime
import subprocess
import argparse
import os
from multiprocessing import Pool

Subjects = {"perses": ["clang-22382", "clang-27137", "clang-23353", "clang-27747", "clang-25900", "clang-22704",
                      "gcc-65383", "gcc-61917", "clang-26760", "gcc-61383", "clang-23309",
                      "gcc-70586", "gcc-66375", "gcc-70127", "clang-26350",
                      "gcc-64990", "clang-31259", "gcc-60116", "gcc-66186", "gcc-59903"
                      ],
            "rcc": ["gcc-66412", "clang-18556", "clang-18596", "clang-19595", "clang-20680", "clang-21467",
                    "clang-21582", "clang-22337", "gcc-60452", "gcc-61047",
                    "gcc-66691"],
            "chisel": ["chisel-bench/date-8.21"],
            "chisel2": ["chisel-bench/grep-2.19"],
            "quick": ["clang-22382", "clang-23353"],
            "large": ["clang-27747", "clang-22704"],
            "long": ["clang-27137", "gcc-70586"],
            "flaky": ["gcc-64990", "gcc-65383", "gcc-66186"],
            "micro": ["gcc-70586"]
            }
Subjects["all"] = Subjects["perses"] + Subjects["rcc"]

Cache = {
    "NO": "--edit-caching false --query-caching false",
    "RCC": "--query-cache-type COMPACT_QUERY_CACHE",
    "SHA": "--query-cache-type CONTENT_SHA512",
    "SHAFORMAT": "--query-cache-type CONTENT_SHA512_FORMAT --code-format COMPACT_ORIG_FORMAT --query-caching TRUE",
    "STR": "--query-cache-type ORIG_CONTENT_STRING_BASED",
    "ZIP": "--query-cache-type CONTENT_ZIP",
    "CC": "--query-cache-refresh-threshold 100 --query-cache-type RCC_MEM_LIT",
    "RSTR": "--query-cache-type CONTENT_LEXEME_LIST_BASE",
    "RCCLIT": "--query-cache-type RCC_MEM_LIT",
    "RCCLIT_size": "--enable-lightweight-refreshing true --query-cache-type RCC_MEM_LIT",
    "RCCFORMAT": "--query-cache-type COMPACT_QUERY_CACHE_FORMAT_SENSITIVE --code-format COMPACT_ORIG_FORMAT --query-caching TRUE"
}


def get_perses_flags():
    return Cache[args.cache]


def get_cmd(subject, idx):
    if args.mode == "time":
        return (f"./run_benchmark.py --subjects {subject} --reducers {args.reducer}  --show-subprocess "
                f"--iterations {idx + 1} --start-iter {idx} -o {output_folder}")
    elif args.mode == "memory":
        return (f"./run_cache_profiling.py --subjects {subject} --reducers {args.reducer} "
                f"--monitor-interval {args.interval} --show-subprocess "
                f"--iterations {idx + 1} --start-iter {idx} -o {output_folder}")
    else:
        raise NotImplementedError


def func(subject_idx):
    subject, idx = subject_idx

    new_env = os.environ.copy()
    if args.mode == "time":
        new_env["JVM_FLAGS"] = "-Xmx64g -da"
    elif args.mode == "memory":
        new_env["JVM_FLAGS"] = "-Xmx64g -da"
    else:
        new_env["JVM_FLAGS"] = "-Xmx40g"
    new_env["PERSES_FLAGS"] = get_perses_flags()

    cmd = get_cmd(subject, idx)

    start_time = datetime.now()
    print("Time {}, Start: ".format(start_time.strftime("%Y%m%d-%H:%M:%S-%f")) + cmd)

    p = subprocess.run(cmd, shell=True, env=new_env, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                       stderr=subprocess.STDOUT)

    if p.returncode != 0:
        p = subprocess.run(cmd, shell=True, env=new_env, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                           stderr=subprocess.STDOUT)

    end_time = datetime.now()
    duration_in_s = (end_time - start_time).total_seconds()

    if p.returncode != 0:
        msg = "Error"
    else:
        msg = "Success"
    print("Time {}, Duration {:.2f}s, {} in {}".format(end_time.strftime("%Y%m%d-%H:%M:%S-%f"), duration_in_s, msg,
                                                       subject))

    stdout_str = p.stdout.decode("utf-8", "ignore")

    return stdout_str


def main():
    jobs = []
    for idx in range(0, args.repeat):
        for subject in Subjects[args.set]:
            jobs.append((subject, idx))

    print(f"Total Tasks: {len(jobs)}")

    with Pool(args.num_cpu) as p:
        results = p.map(func, jobs)

    with open(log_file, "w") as output:
        json.dump(results, output)

def is_file_in_current_directory(filename):
    current_directory = os.getcwd()  # Get the current working directory
    file_path = os.path.join(current_directory, filename)  # Create the full file path
    return os.path.isfile(file_path)  # Check if the file exists in the current directory


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", dest="num_cpu", type=int, default=1, help="the number of cpu to be used")
    parser.add_argument("--set", required=True, help="the set of subjects: \n " + str(list(Subjects.keys())))
    parser.add_argument("--cache", required=True, help="type of cache \n " + str(list(Cache.keys())))
    parser.add_argument("--mode", required=True, choices=["memory", "time"], help="measure memory or time")
    parser.add_argument("--repeat", default=1, type=int, help="repeat")
    parser.add_argument("--reducer", default="perses", type=str, choices=["hdd", "perses"], help="reducer")
    parser.add_argument("--interval", default=600000, type=int, help="interval for measure RAM")
    #     parser.add_argument("--no-cache", action='store_false', help="disable global cache")

    if not is_file_in_current_directory("run_benchmark.py") or not is_file_in_current_directory("run_cache_profiling.py"):
        raise Exception("this script should be called from the benchmark folder."
                        "Such as python3 rcc-exp-script/run_benchmark_parallel.py")

    args = parser.parse_args()

    assert args.set in list(Subjects.keys())
    assert args.cache in list(Cache.keys())

    timestamp = datetime.now().strftime("%Y%m%d-%H:%M:%S-%f")
    suffix_str = "{}_{}_{}_{}_{}".format(args.reducer, args.cache, args.set, args.mode, timestamp)
    output_folder = "benchmark_results_{}".format(suffix_str)
    log_file = "RCC-Exp-stdout-{}.json".format(suffix_str)

    print(args)

    main()
