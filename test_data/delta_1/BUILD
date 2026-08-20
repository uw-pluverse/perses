load("//:perses.bzl", "reduce")

package(default_visibility = ["//test/org/perses:__subpackages__"])

filegroup(
    name = "delta_1",
    srcs = [
        "r.sh",
        "slow_r.sh",
        "t.c",
    ],
)

reduce(
    name = "reduce_delta_1_with_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_cache.c",
    reduction_algorithm = "node-dfs",
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
    reduction_algorithm = "node-dfs",
    source_file = "t.c",
    statistics_file = "stat_t_wo_cache.c",
    test_script = "r.sh",
)

filegroup(
    name = "log_with_level_below_INFO",
    srcs = ["reduce_delta_1_with_caching_reduction_log.txt"],
)
