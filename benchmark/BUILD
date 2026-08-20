load("@rules_python//python:defs.bzl", "py_binary", "py_library", "py_test")

package(default_visibility = [
    "//visibility:public",
])

py_library(
    name = "run_benchmark",
    srcs = ["run_benchmark.py"],
)

py_binary(
    name = "convert_memory_log_to_csv",
    srcs = ["convert_memory_log_to_csv.py"],
)

py_binary(
    name = "convert_time_query_to_csv",
    srcs = ["convert_time_query_to_csv.py"],
)

py_library(
    name = "plot_program_trend",
    srcs = ["plot_program_trend.py"],
)

py_test(
    name = "plot_program_trend_test",
    srcs = ["plot_program_trend_test.py"],
    deps = [":plot_program_trend"],
)

py_test(
    name = "run_benchmark_test",
    srcs = ["run_benchmark_test.py"],
    data = [
        "//benchmark/clang-22382:files",
    ],
    deps = [":run_benchmark"],
)

py_test(
    name = "convert_memory_log_to_csv_test",
    srcs = ["convert_memory_log_to_csv_test.py"],
    deps = [":convert_memory_log_to_csv"],
)

py_test(
    name = "convert_time_query_to_csv_test",
    srcs = ["convert_time_query_to_csv_test.py"],
    deps = [":convert_time_query_to_csv"],
)
