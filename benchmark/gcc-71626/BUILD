package(default_visibility = ["//visibility:public"])

load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

filegroup(
    name = "gcc71626",
    srcs = [
        "r.sh",
        "small.c",
    ],
)

sanity_test(
    name = "sanity_test",
    source_file = "small.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_perses.c",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "small.c",
    test_script = "r.sh",
)
