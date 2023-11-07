#package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

sanity_test(
    name = "sanity_test",
    source_files = ["t.vert"],
    test_script = "grep_based_r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_t.vert",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.vert",
    test_script = "grep_based_r.sh",
)
