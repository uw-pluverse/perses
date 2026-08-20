load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = [
        "t.c",
    ],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "LAYER_BY_LAYER_TOP_DOWN",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_no_reducing_regular_rule_node",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_progress_no_rule_node.txt",
    golden_reduced_file = "golden_reduced_no_rule_node_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "LAYER_BY_LAYER_TOP_DOWN",
        "--enable-reducing-regular-rule-node": "false",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)
