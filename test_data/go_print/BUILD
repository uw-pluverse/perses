load("//src/org/perses:reduction.bzl", "reduce")

package(default_visibility = ["//test/org/perses:__subpackages__"])

filegroup(
    name = "go_print",
    srcs = [
        "r.sh",
        "small.go",
    ],
)

reduce(
    name = "reduce_go_print",
    enable_edit_caching = True,
    enable_query_caching = True,
    progress_dump_file = "progress_dump.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    result_file = "small_reduced.go",
    source_file = "small.go",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)


filegroup(
    name = "go_print_reduced",
    srcs = [
        "progress_dump.txt",
        "small_reduced.go",
        "statistics.txt",
    ],
)
