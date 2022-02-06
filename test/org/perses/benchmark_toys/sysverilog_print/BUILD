package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//src/org/perses:reduction.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

sanity_test(
    name = "sanity_test",
    source_files = ["hello.sv"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_file = "golden.sv",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "hello.sv",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)
