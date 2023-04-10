package(default_visibility = [
    "//visibility:public",
])

filegroup(
    name = "sanity_test",
    srcs = ["sanity_test.sh"],
)

py_binary(
    name = "run_benchmark",
    srcs = ["run_benchmark.py"],
)

py_binary(
    name = "analyze_cache_profiling",
    srcs = ["analyze_cache_profiling.py"],
)

py_binary(
    name = "convert_result_to_csv",
    srcs = ["convert_result_to_csv.py"],
)

py_test(
    name = "run_benchmark_test",
    srcs = ["run_benchmark_test.py"],
    deps = ["run_benchmark"],
)

py_test(
    name = "analyze_cache_profiling_test",
    srcs = ["analyze_cache_profiling_test.py"],
    deps = ["analyze_cache_profiling"],
)

py_test(
    name = "convert_result_to_csv_test",
    srcs = ["convert_result_to_csv_test.py"],
    deps = ["convert_result_to_csv"],
)
