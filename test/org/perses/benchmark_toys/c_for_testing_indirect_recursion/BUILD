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
    name = "mimir_reduction_dag_as_list_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
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
    name = "mimir_reduction_fine_dag_as_list_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_mimir_fine_dag_as_list_progress.txt",
    golden_reduced_file = "golden_mimir_fine_dag_as_list_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "FINE_DAG_AS_LIST",
        "--enable-mimir-delete-def-with-all-its-concrete-uses": "false",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_with_different_cleanup_reducer_fine_dag_as_list_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_mimir_with_different_cleanup_reducer_fine_dag_as_list_progress.txt",
    golden_reduced_file = "golden_mimir_with_different_cleanup_fine_dag_as_list_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "FINE_DAG_AS_LIST",
        "--enable-mimir-delete-def-with-all-its-concrete-uses": "false",
        "--cleanup-alg": "node_priority",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_finer_dag_as_list_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_mimir_finer_dag_as_list_progress.txt",
    golden_reduced_file = "golden_mimir_finer_dag_as_list_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "FINER_DAG_AS_LIST",
        "--enable-mimir-delete-def-with-all-its-concrete-uses": "false",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_dag_as_list_enable_delete_def_with_all_its_concrete_uses_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_list_minimizer_profile = "golden_list_minimizer_dag_as_list_delete_def_with_uses_profile.txt",
    golden_progress_file = "golden_mimir_dag_as_list_delete_def_with_uses_progress.txt",
    golden_reduced_file = "golden_mimir_dag_as_list_delete_def_with_uses_reduced_t.c",
    other_flags = {
        "--mimir-reduction-algorithm": "DAG_AS_LIST",
        "--enable-mimir-delete-def-with-all-its-concrete-uses": "true",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "without_mimir_on_regular_node_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_list_minimizer_profile = "golden_list_minimizer_without_mimir_on_regular_node_profile.txt",
    golden_progress_file = "golden_mimir_without_mimir_on_regular_node_progress.txt",
    golden_reduced_file = "golden_mimir_without_mimir_on_regular_node_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "DAG_AS_LIST",
        "--enable-mimir-for-regular-node": "false",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_dfs_dag_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_list_minimizer_profile = "golden_list_minimizer_dfs_dag_profile.txt",
    golden_progress_file = "golden_mimir_dfs_dag_progress.txt",
    golden_reduced_file = "golden_mimir_dfs_dag_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "DFS_DAG",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_list_minimizer_profile = "golden_list_minimizer_profile.txt",
    golden_progress_file = "golden_mimir_progress.txt",
    golden_reduced_file = "golden_mimir_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "LAYER_BY_LAYER_BOTTOM_UP",
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "perses_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_perses_progress.txt",
    golden_reduced_file = "golden_perses_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
    },
    reduction_algorithm = "node_priority",
    source_file = "t.c",
    test_script = "r.sh",
)
