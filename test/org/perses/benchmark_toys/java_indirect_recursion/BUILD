load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = [
        "Hello.java.txt",
    ],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "perses_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_perses_progress.txt",
    golden_reduced_file = "golden_perses_reduced_Hello.java.txt",
    other_flags = {
        "--lang": "java",
        "--enable-latra": "false",
    },
    reduction_algorithm = "node_priority",
    source_file = "Hello.java.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_dag_as_list_javac_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_mimir_javac_dag_as_list_progress.txt",
    golden_reduced_file = "golden_mimir_javac_dag_as_list_reduced_Hello.java.txt",
    other_flags = {
        "--lang": "java",
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "DAG_AS_LIST",
        "--mimir-java-language-server-cmd": "javac",
    },
    reduction_algorithm = "mimir",
    source_file = "Hello.java.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_fine_dag_as_list_javac_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_mimir_javac_fine_dag_as_list_progress.txt",
    golden_reduced_file = "golden_mimir_javac_fine_dag_as_list_reduced_Hello.java.txt",
    other_flags = {
        "--lang": "java",
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "FINE_DAG_AS_LIST",
        "--enable-mimir-delete-def-with-all-its-concrete-uses": "false",
        "--mimir-java-language-server-cmd": "javac",
    },
    reduction_algorithm = "mimir",
    source_file = "Hello.java.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_finer_dag_as_list_javac_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_mimir_javac_finer_dag_as_list_progress.txt",
    golden_reduced_file = "golden_mimir_javac_finer_dag_as_list_reduced_Hello.java.txt",
    other_flags = {
        "--lang": "java",
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "FINER_DAG_AS_LIST",
        "--enable-mimir-delete-def-with-all-its-concrete-uses": "false",
        "--mimir-java-language-server-cmd": "javac",
    },
    reduction_algorithm = "mimir",
    source_file = "Hello.java.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_dfs_dag_javac_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_mimir_javac_dfs_dag_progress.txt",
    golden_reduced_file = "golden_mimir_javac_dfs_dag_reduced_Hello.java.txt",
    other_flags = {
        "--lang": "java",
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "DFS_DAG",
        "--mimir-java-language-server-cmd": "javac",
    },
    reduction_algorithm = "mimir",
    source_file = "Hello.java.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_javac_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = False,
    golden_progress_file = "golden_mimir_javac_progress.txt",
    golden_reduced_file = "golden_mimir_javac_reduced_Hello.java.txt",
    other_flags = {
        "--lang": "java",
        "--enable-latra": "false",
        "--mimir-reduction-algorithm": "LAYER_BY_LAYER_BOTTOM_UP",
        "--mimir-java-language-server-cmd": "javac",
    },
    reduction_algorithm = "mimir",
    source_file = "Hello.java.txt",
    test_script = "r.sh",
)
