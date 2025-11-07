load("//benchmark:benchmark.bzl", "sanity_test")
load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")

PERSES_LIST_DIFF_REDUCER_BIN = "//ppr/src/org/perses/ppr/diff/list:main"

sanity_test(
    name = "sanity_test_insert_two_stmts",
    source_files = [
        "seed.c",
        "variant.c",
    ],
    test_script = "r.sh",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_ddmin_insert_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_ddmin.txt",
    golden_reduced_seed_file = "golden_reduced_seed.c",
    golden_reduced_variant_file = "golden_reduced_variant.c",
    log_file = "reduction_golden_test_ddmin.log",
    other_flags = {
        "--enable-diff-ddmin": "true",
        "--enable-diff-slicer": "false",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_ddmin.txt",
    reduction_algorithm = "node_priority-dfs",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_slicer_insert_two_stmts",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_slicer.txt",
    golden_reduced_seed_file = "golden_reduced_seed.c",
    golden_reduced_variant_file = "golden_reduced_variant.c",
    log_file = "reduction_golden_test_slicer.log",
    other_flags = {
        "--enable-diff-ddmin": "false",
        "--enable-diff-slicer": "true",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress_slicer.txt",
    reduction_algorithm = "node_priority-dfs",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)
