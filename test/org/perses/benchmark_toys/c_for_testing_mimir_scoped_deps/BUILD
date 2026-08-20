load("//test:test.bzl", "golden_test", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = [
        "t.c",
    ],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_mimir_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    extra_output_files = [
        "reduction-process.yaml",
    ],
    golden_progress_file = "golden_mimir_progress.txt",
    golden_reduced_file = "golden_mimir_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "LAYER_BY_LAYER_TOP_DOWN",
        "--profile-for-reduction-progress-differential-analysis": "$(location reduction-process.yaml)",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

golden_test(
    name = "golden_test_reduction_process_yaml",
    golden_file = "golden_reduction_process.yaml",
    test_file = "reduction-process.yaml",
)

reduction_golden_test(
    name = "reduction_mimir_with_deleting_externally_used_nodes_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_mimir_with_deleting_externally_used_nodes_progress.txt",
    golden_reduced_file = "golden_mimir_with_deleting_externally_used_nodes_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "LAYER_BY_LAYER_TOP_DOWN_PLUS",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_mimir_dag_as_list_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_list_minimizer_profile = "golden_list_minimizer_dag_as_list_profile.txt",
    golden_progress_file = "golden_mimir_dag_as_list_progress.txt",
    golden_reduced_file = "golden_mimir_dag_as_list_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "DAG_AS_LIST",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_perses_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_perses_progress.txt",
    golden_reduced_file = "golden_perses_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
    },
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_mimir_bottom_layer_first_then_topdown_plus_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_mimir_bottom_layer_first_then_topdown_plus_progress.txt",
    golden_reduced_file = "golden_mimir_bottom_layer_first_then_topdown_plus_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "BOTTOM_LAYER_FIRST_THEN_TOPDOWN_PLUS",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)
