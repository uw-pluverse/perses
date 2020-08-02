load("//src/org/perses:reduction.bzl", "reduce")

package(default_visibility = ["//test/org/perses:__subpackages__"])

filegroup(
    name = "delta_1",
    srcs = [
        "r.sh",
        "t.c",
    ],
)

reduce(
    name = "reduce_delta_1_with_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_cache.c",
    reduction_algorithm = "perses_node_with_dfs_delta",
    result_file = "reduced_t.c",
    source_file = "t.c",
    statistics_file = "stat_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)

reduce(
    name = "reduce_delta_1_wo_caching",
    enable_edit_caching = False,
    enable_query_caching = False,
    progress_dump_file = "progress_dump_t_wo_cache.c",
    reduction_algorithm = "perses_node_with_dfs_delta",
    result_file = "reduced_t_wo_cache.c",
    source_file = "t.c",
    statistics_file = "stat_t_wo_cache.c",
    test_script = "r.sh",
)

filegroup(
    name = "log_with_level_below_INFO",
    srcs = ["reduce_delta_1_with_caching_reduction_log.txt"],
)

filegroup(
    name = "delta_1_reduced",
    srcs = [
        "progress_dump_t_with_cache.c",
        "reduce_delta_1_with_caching.log",
        "reduced_t.c",
        "stat_t.c",
    ],
)
