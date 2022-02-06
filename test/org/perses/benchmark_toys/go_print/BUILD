package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//src/org/perses:reduction.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["small.go"],
    test_script = "r.sh",
)

filegroup(
    name = "go_print",
    srcs = [
        "r.sh",
        "small.go",
    ],
)

name_reduce_go_print = "reduce_go_print"

output_dir_reduce_go_print = "output_dir_%s" % name_reduce_go_print

reduce(
    name = name_reduce_go_print,
    enable_edit_caching = True,
    enable_query_caching = True,
    other_flags = {
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    output_dir = output_dir_reduce_go_print,
    progress_dump_file = "progress_dump.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "small.go",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_small.go",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "small.go",
    test_script = "r.sh",
)
