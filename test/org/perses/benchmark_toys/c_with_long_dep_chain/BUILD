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
    golden_list_minimizer_profile = "golden_list_minimizer_profile.txt",
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
    name = "reduction_golden_test_mimir_from_bottom_to_top",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_progress_from_bottom_to_top.txt",
    golden_reduced_file = "golden_reduced_from_bottom_to_top_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "LAYER_BY_LAYER_BOTTOM_UP",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_wo_mimir",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_progress_wo_mimir.txt",
    golden_reduced_file = "golden_reduced_t_wo_mimir.c",
    other_flags = {
        "--enable-latra": "false",
    },
    reduction_algorithm = "node_priority",
    source_file = "t.c",
    test_script = "r.sh",
)
