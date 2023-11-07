load("//benchmark:benchmark.bzl", "sanity_test")
load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

PERSES_LIST_DIFF_REDUCER_BIN = "//ppr/src/org/perses/ppr/diff/list:main"

sanity_test(
    name = "sanity_test_insert_two_stmts",
    source_files = [
        "seed_insert_two_stmts.c",
        "variant_insert_two_stmts.c",
    ],
    test_script = "r_insert_two_stmts.sh",
)

sanity_test(
    name = "sanity_test_swap_two_variables",
    source_files = [
        "seed_swap_two_variables.c",
        "variant_swap_two_variables.c",
    ],
    test_script = "r_swap_two_variables.sh",
)

sanity_test(
    name = "sanity_test_replace_a_stmt",
    source_files = [
        "seed_replace_a_stmt.c",
        "variant_replace_a_stmt.c",
    ],
    test_script = "r_replace_a_stmt.sh",
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
    name = "list_diff_reduction_golden_test_ddmin_insert_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_ddmin_insert_two_stmts.txt",
    golden_reduced_seed_file = "golden_reduced_seed_insert_two_stmts.c",
    golden_reduced_variant_file = "golden_reduced_variant_insert_two_stmts.c",
    log_file = "reduction_golden_test_ddmin_insert_two_stmts.log",
    other_flags = {
        "--enable-diff-ddmin": "true",
        "--enable-diff-slicer": "false",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_ddmin_insert_two_stmts.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_insert_two_stmts.c",
    test_script = "r_insert_two_stmts.sh",
    thread_count = 1,
    variant_file = "variant_insert_two_stmts.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_ddmin_swap_two_variables",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_ddmin_swap_two_variables.txt",
    golden_reduced_seed_file = "golden_reduced_seed_swap_two_variables.c",
    golden_reduced_variant_file = "golden_reduced_variant_swap_two_variables.c",
    log_file = "reduction_golden_test_ddmin_swap_two_variables.log",
    other_flags = {
        "--enable-diff-ddmin": "true",
        "--enable-diff-slicer": "false",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_ddmin_swap_two_variables.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_swap_two_variables.c",
    test_script = "r_swap_two_variables.sh",
    thread_count = 1,
    variant_file = "variant_swap_two_variables.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_ddmin_replace_a_stmt",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_ddmin_replace_a_stmt.txt",
    golden_reduced_seed_file = "golden_reduced_seed_replace_a_stmt.c",
    golden_reduced_variant_file = "golden_reduced_variant_replace_a_stmt.c",
    log_file = "reduction_golden_test_ddmin_replace_a_stmt.log",
    other_flags = {
        "--enable-diff-ddmin": "true",
        "--enable-diff-slicer": "false",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_ddmin_replace_a_stmt.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_replace_a_stmt.c",
    test_script = "r_replace_a_stmt.sh",
    thread_count = 1,
    variant_file = "variant_replace_a_stmt.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_ddmin_delete_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_ddmin_delete_two_stmts.txt",
    golden_reduced_seed_file = "golden_reduced_seed_delete_two_stmts.c",
    golden_reduced_variant_file = "golden_reduced_variant_delete_two_stmts.c",
    log_file = "reduction_golden_test_ddmin_delete_two_stmts.log",
    other_flags = {
        "--enable-diff-ddmin": "true",
        "--enable-diff-slicer": "false",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_ddmin_delete_two_stmts.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_delete_two_stmts.c",
    test_script = "r_delete_two_stmts.sh",
    thread_count = 1,
    variant_file = "variant_delete_two_stmts.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_slicer_insert_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_slicer_insert_two_stmts.txt",
    golden_reduced_seed_file = "golden_reduced_seed_insert_two_stmts.c",
    golden_reduced_variant_file = "golden_reduced_variant_insert_two_stmts.c",
    log_file = "reduction_golden_test_slicer_insert_two_stmts.log",
    other_flags = {
        "--enable-diff-ddmin": "false",
        "--enable-diff-slicer": "true",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_slicer_insert_two_stmts.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_insert_two_stmts.c",
    test_script = "r_insert_two_stmts.sh",
    thread_count = 1,
    variant_file = "variant_insert_two_stmts.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_slicer_swap_two_variables",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_slicer_swap_two_variables.txt",
    golden_reduced_seed_file = "golden_reduced_seed_swap_two_variables.c",
    golden_reduced_variant_file = "golden_reduced_variant_swap_two_variables.c",
    log_file = "reduction_golden_test_slicer_swap_two_variables.log",
    other_flags = {
        "--enable-diff-ddmin": "false",
        "--enable-diff-slicer": "true",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_slicer_swap_two_variables.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_swap_two_variables.c",
    test_script = "r_swap_two_variables.sh",
    thread_count = 1,
    variant_file = "variant_swap_two_variables.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_slicer_replace_a_stmt",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_slicer_replace_a_stmt.txt",
    golden_reduced_seed_file = "golden_reduced_seed_replace_a_stmt.c",
    golden_reduced_variant_file = "golden_reduced_variant_replace_a_stmt.c",
    log_file = "reduction_golden_test_slicer_replace_a_stmt.log",
    other_flags = {
        "--enable-diff-ddmin": "false",
        "--enable-diff-slicer": "true",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_slicer_replace_a_stmt.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_replace_a_stmt.c",
    test_script = "r_replace_a_stmt.sh",
    thread_count = 1,
    variant_file = "variant_replace_a_stmt.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_slicer_delete_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_slicer_delete_two_stmts.txt",
    golden_reduced_seed_file = "golden_reduced_seed_delete_two_stmts.c",
    golden_reduced_variant_file = "golden_reduced_variant_delete_two_stmts.c",
    log_file = "reduction_golden_test_slicer_delete_two_stmts.log",
    other_flags = {
        "--enable-diff-ddmin": "false",
        "--enable-diff-slicer": "true",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_slicer_delete_two_stmts.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed_delete_two_stmts.c",
    test_script = "r_delete_two_stmts.sh",
    thread_count = 1,
    variant_file = "variant_delete_two_stmts.c",
)

kt_jvm_test(
    name = "ListDiffOutputManagerFactoryTest",
    srcs = ["ListDiffOutputManagerFactoryTest.kt"],
    deps = [
        "//ppr/src/org/perses/ppr/diff:ppr_diff_utils",
        "//ppr/src/org/perses/ppr/diff/list:output_manager",
        "//ppr/src/org/perses/ppr/diff/list:reduction_inputs",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/program/printer",
        "//src/org/perses/util:perses_diffutil",
        "//test/org/perses:test_util",
    ],
)
