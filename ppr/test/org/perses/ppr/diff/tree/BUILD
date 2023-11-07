load("//benchmark:benchmark.bzl", "sanity_test")
load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

PERSES_TREE_DIFF_REDUCER_BIN = "//ppr/src/org/perses/ppr/diff/tree:main"

sanity_test(
    name = "sanity_test_insert_two_stmts",
    source_files = [
        "seed_insert_two_stmts.c",
        "variant_insert_two_stmts.c",
    ],
    test_script = "r_insert_two_stmts.sh",
)

sanity_test(
    name = "sanity_test_delete_two_stmts",
    source_files = [
        "seed_delete_two_stmts.c",
        "variant_delete_two_stmts.c",
    ],
    test_script = "r_delete_two_stmts.sh",
)

ppr_reduction_golden_test(
    name = "tree_diff_reduction_golden_test_ddmin_insert_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_insert_two_stmts.txt",
    golden_reduced_seed_file = "golden_reduced_seed_insert_two_stmts.c",
    golden_reduced_variant_file = "golden_reduced_variant_insert_two_stmts.c",
    log_file = "reduction_golden_test_ddmin_insert_two_stmts.log",
    perses_bin = PERSES_TREE_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_insert_two_stmts.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_insert_two_stmts.c",
    test_script = "r_insert_two_stmts.sh",
    thread_count = 1,
    variant_file = "variant_insert_two_stmts.c",
)

ppr_reduction_golden_test(
    name = "tree_diff_reduction_golden_test_ddmin_delete_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_delete_two_stmts.txt",
    golden_reduced_seed_file = "golden_reduced_seed_delete_two_stmts.c",
    golden_reduced_variant_file = "golden_reduced_variant_delete_two_stmts.c",
    log_file = "reduction_golden_test_ddmin_delete_two_stmts.log",
    perses_bin = PERSES_TREE_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_delete_two_stmts.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_delete_two_stmts.c",
    test_script = "r_delete_two_stmts.sh",
    thread_count = 1,
    variant_file = "variant_delete_two_stmts.c",
)
