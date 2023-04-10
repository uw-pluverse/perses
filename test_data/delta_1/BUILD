load("//src/org/perses:reduction.bzl", "reduce")

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
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    statistics_file = "stat_t.c",
    test_script = "r.sh",
    verbosity = "CONFIG",
)

reduce(
    name = "reduce_delta_1_with_content_string_based_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_content_string_based_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_content_string_based_cache_process.log",
    query_cache_type = "ORIG_CONTENT_STRING_BASED",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_content_sha512_based_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_content_sha512_based_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_content_sha512_based_cache_process.log",
    query_cache_type = "CONTENT_SHA512",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_content_zip_based_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_content_zip_based_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_content_zip_based_cache_process.log",
    query_cache_type = "CONTENT_ZIP",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_content_lexeme_list_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_content_lexeme_list_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_content_lexeme_list_cache_process.log",
    query_cache_type = "CONTENT_LEXEME_LIST_BASE",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_config_based_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_config_based_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_config_based_cache_process.log",
    query_cache_type = "CONFIG_BASED",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_lexeme_id_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_lexeme_id_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_lexeme_id_cache_process.log",
    query_cache_type = "PERSES_LEXEME_ID",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_fast_linear_scan_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_fast_linear_scan_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_fast_linear_scan_cache_process.log",
    query_cache_type = "COMPACT_QUERY_CACHE",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_fast_linear_scan_without_compression_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_fast_linear_scan_without_compression_caching_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_fast_linear_scan_without_compression_cache_process.log",
    query_cache_type = "PERSES_FAST_LINEAR_SCAN_NO_COMPRESSION",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_with_rcc_mem_lit",
    enable_edit_caching = True,
    enable_query_caching = True,
    log_file = "reduce_delta_1_with_rcc_mem_lit_query_cache_reduction_log.txt",
    progress_dump_file = "progress_dump_t_with_rcc_mem_lit_cache_process.log",
    query_cache_type = "RCC_MEM_LIT",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

reduce(
    name = "reduce_delta_1_wo_caching",
    enable_edit_caching = False,
    enable_query_caching = False,
    progress_dump_file = "progress_dump_t_wo_cache.c",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "t.c",
    statistics_file = "stat_t_wo_cache.c",
    test_script = "r.sh",
)

filegroup(
    name = "log_with_level_below_INFO",
    srcs = ["reduce_delta_1_with_caching_reduction_log.txt"],
)

filegroup(
    name = "progress_dump_t_with_fast_linear_scan_cache_process",
    srcs = ["progress_dump_t_with_fast_linear_scan_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_fast_linear_scan_without_compression_cache_process",
    srcs = ["progress_dump_t_with_fast_linear_scan_without_compression_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_lexeme_id_cache_process",
    srcs = ["progress_dump_t_with_lexeme_id_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_content_string_based_cache_process",
    srcs = ["progress_dump_t_with_content_string_based_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_content_sha512_based_cache_process",
    srcs = ["progress_dump_t_with_content_sha512_based_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_content_zip_based_cache_process",
    srcs = ["progress_dump_t_with_content_zip_based_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_content_lexeme_list_cache_process",
    srcs = ["progress_dump_t_with_content_lexeme_list_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_config_based_cache_process",
    srcs = ["progress_dump_t_with_config_based_cache_process.log"],
)

filegroup(
    name = "progress_dump_t_with_rcc_mem_lit_cache_process",
    srcs = ["progress_dump_t_with_rcc_mem_lit_cache_process.log"],
)
