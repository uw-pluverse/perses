load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.smt2"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_reduced_file = "golden.smt2",
    reduction_algorithm = "node_priority-dfs",
    source_file = "hello.smt2",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "vulcan_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    enable_vulcan = True,
    golden_reduced_file = "vulcan_golden.smt2",
    reduction_algorithm = "node_priority-dfs",
    source_file = "hello.smt2",
    test_script = "r.sh",
)
