package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//src/org/perses:reduction.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

sanity_test(
    name = "sanity_test",
    source_files = ["Hello.sc"],
    test_script = "r.sh",
)

filegroup(
    name = "scala_print",
    srcs = [
        "Hello.sc",
        "r.sh",
    ],
)

reduce(
    name = "reduce_scala_print",
    enable_edit_caching = True,
    enable_query_caching = True,
    output_dir = "output_dir_reduce_scala_print",
    progress_dump_file = "progress_dump.txt",
    query_cache_type = "COMPACT_QUERY_CACHE_FORMAT_SENSITIVE",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "Hello.sc",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)

reduce(
    name = "reduce_with_global_cache",
    enable_edit_caching = False,
    enable_query_caching = False,
    extra_output_files = ["updated_global_cache.csv"],
    other_flags = {
        "--global-cache-file": "$(location golden_global_cache.csv)",
        "--path-to-save-updated-global-cache": "$(location updated_global_cache.csv)",
    },
    output_dir = "output_dir_reduce_with_global_cache",
    progress_dump_file = "progress_dump_reduced_with_global_cache.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "Hello.sc",
    test_script = "r.sh",
    deps = [
        "golden_global_cache.csv",
    ],
)

golden_test(
    name = "golden_test_global_cache",
    golden_file = "golden_global_cache.csv",
    test_file = "updated_global_cache.csv",
)

golden_test(
    name = "golden_test_progress_dump_reduced_with_global_cache",
    golden_file = "golden_progress_dump_reduced_with_global_cache.txt",
    test_file = "progress_dump_reduced_with_global_cache.txt",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_Hello.sc",
    other_flags = {
        "--query-cache-type": "COMPACT_QUERY_CACHE_FORMAT_SENSITIVE",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_line_slicer",
    enable_query_caching = True,
    golden_reduced_file = "golden_reduced_Hello_line_slicer.sc",
    other_flags = {
        "--enable-line-slicer": "true",
        "--query-cache-type": "COMPACT_QUERY_CACHE_FORMAT_SENSITIVE",
    },
    reduction_algorithm = "line_based_concurrent_token_slicer",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

reduce(
    name = "reduce_scala_print_with_token_slicer",
    enable_edit_caching = True,
    enable_query_caching = True,
    other_flags = {
        "--enable-token-slicer": "true",
        "--query-cache-type": "COMPACT_QUERY_CACHE_FORMAT_SENSITIVE",
    },
    output_dir = "reduce_scala_print_with_token_slicer_output_dir",
    progress_dump_file = "reduce_scala_print_with_token_slicer_reduction_progress.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_token_slicer",
    golden_file = "golden_reduced_hello_with_token_slicer.sc",
    test_file = "reduce_scala_print_with_token_slicer_output_dir/Hello.sc",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_token_slicer_progress",
    golden_file = "gold_test_reduce_scala_print_with_token_slicer_progress.txt",
    test_file = "reduce_scala_print_with_token_slicer_reduction_progress.txt",
)

reduce(
    name = "reduce_scala_print_with_tree_slicer",
    enable_edit_caching = True,
    enable_query_caching = True,
    other_flags = {
        "--enable-tree-slicer": "true",
        "--query-cache-type": "COMPACT_QUERY_CACHE_FORMAT_SENSITIVE",
    },
    output_dir = "reduce_scala_print_with_tree_slicer_output_dir",
    progress_dump_file = "reduce_scala_print_with_tree_slicer_reduction_progress.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_tree_slicer",
    golden_file = "golden_reduced_hello_with_tree_slicer.sc",
    test_file = "reduce_scala_print_with_tree_slicer_output_dir/Hello.sc",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_tree_slicer_progress",
    golden_file = "gold_test_reduce_scala_print_with_tree_slicer_progress.txt",
    test_file = "reduce_scala_print_with_tree_slicer_reduction_progress.txt",
)
