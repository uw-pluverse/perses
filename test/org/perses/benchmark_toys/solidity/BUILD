load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.sol"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_file = "golden.sol",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "hello.sol",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)

filegroup(
    name = "solidity_program",
    srcs = [
        "hello.sol",
    ],
)
