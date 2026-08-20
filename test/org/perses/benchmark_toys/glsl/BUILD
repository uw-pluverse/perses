#package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//test:test.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["t.vert"],
    test_script = "grep_based_r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_reduced_file = "golden_t.vert",
    reduction_algorithm = "node_priority",
    source_file = "t.vert",
    test_script = "grep_based_r.sh",
)
