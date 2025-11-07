load("//:perses.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

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

reduction_golden_test(
    name = "golden_test_with_global_cache",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_global_cache_file = "golden_global_cache.csv",
    golden_progress_file = "golden_progress_dump_reduced_with_global_cache.txt",
    golden_reduced_file = "golden_global_cache_reduced.Hello.sc",
    reduction_algorithm = "node-dfs",
    source_file = "Hello.sc",
    test_script = "r.sh",
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
    reduction_algorithm = "node_priority-dfs",
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

reduction_golden_test(
    name = "reduction_golden_test_token_slicer",
    enable_query_caching = True,
    golden_global_cache_file = "golden_global_cache_for_token_slicer.csv",
    golden_progress_file = "golden_progress_token_slicer.txt",
    golden_reduced_file = "golden_reduced_Hello_token_slicer.sc",
    reduction_algorithm = "token_slicer",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "golden_test_reduce_scala_print_with_token_slicer",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_global_cache_file = "golden_global_cache_for_concurrent_token_slicer.csv",
    golden_progress_file = "gold_test_reduce_scala_print_with_token_slicer_progress.txt",
    golden_reduced_file = "golden_reduced_hello_with_token_slicer.sc",
    other_flags = {
        "--enable-token-slicer": "true",
        "--query-cache-type": "COMPACT_QUERY_CACHE_FORMAT_SENSITIVE",
    },
    source_file = "Hello.sc",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "golden_test_reduce_scala_print_with_tree_slicer",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_global_cache_file = "golden_global_cache_for_tree_slicer.csv",
    golden_progress_file = "gold_test_reduce_scala_print_with_tree_slicer_progress.txt",
    golden_reduced_file = "golden_reduced_hello_with_tree_slicer.sc",
    other_flags = {
        "--enable-tree-slicer": "true",
        "--fully-deterministic-mode": "true",
        "--query-cache-type": "COMPACT_QUERY_CACHE_FORMAT_SENSITIVE",
    },
    reduction_algorithm = "node-dfs",
    source_file = "Hello.sc",
    test_script = "r.sh",
)
