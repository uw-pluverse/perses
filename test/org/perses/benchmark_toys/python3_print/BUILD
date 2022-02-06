package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//src/org/perses:reduction.bzl", "reduce")
load("//test/org/perses:test.bzl", "golden_test")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["hello.py"],
    test_script = "r.sh",
)

filegroup(
    name = "python3_print",
    srcs = [
        "hello.py",
        "r.sh",
    ],
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_hello.py",
    other_flags = {
        "--code-format": "PYTHON3_FORMAT",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "hello.py",
    test_script = "r.sh",
)
