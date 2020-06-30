package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//src/org/perses:reduction.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_file = "30606.go",
    test_script = "r.sh",
)

filegroup(
    name = "go_30606",
    srcs = [
        "30606.go",
        "r.sh",
    ],
)

reduce(
    name = "reduce_go_30606",
    enable_edit_caching = True,
    enable_query_caching = True,
    progress_dump_file = "progress_dump.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    result_file = "30606_reduced.go",
    source_file = "30606.go",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_30606.go",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "30606.go",
    test_script = "r.sh",
)

filegroup(
    name = "go_30606_reduced",
    srcs = [
        "30606_reduced.go",
        "progress_dump.txt",
        "statistics.txt",
    ],
)
