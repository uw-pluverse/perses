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
    name = "snapshot_generator",
    srcs = ["snapshot_generator.py"],
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
    name = "snapshot_generator_test",
    srcs = ["snapshot_generator_test.py"],
    deps = ["snapshot_generator"],
)
