package(default_visibility = [
    "//benchmark:__subpackages__",
    "//test/org/perses/benchmark_toys:__subpackages__",
])

filegroup(
    name = "sanity_test",
    srcs = ["sanity_test.sh"],
)

py_library(
    name = "analyze_memory",
    srcs = ["analyze_memory.py"],
)

py_test(
    name = "test_analyze_memory",
    srcs = ["test_analyze_memory.py"],
    deps = [
        ":analyze_memory",
    ],
)
