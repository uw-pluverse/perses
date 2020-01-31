package(default_visibility = ["//visibility:public"])

load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_file = "small.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    golden_reduced_file = "golden_perses.c",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "small.c",
    test_script = "r.sh",
)
