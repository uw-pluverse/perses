load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.js"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_file = "golden.js",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "hello.js",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)

# https://github.com/chengniansun/perses-private/issues/749
reduction_golden_test(
    name = "vulcan_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_file = "vulcan_golden.js",
    other_flags = {
        "--enable-vulcan": "true",
    },
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "hello.js",
    test_script = "r.sh",
)
