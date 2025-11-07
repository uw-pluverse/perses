load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")

PERSES_LIST_DIFF_REDUCER_BIN = "//ppr/src/org/perses/ppr/diff/list:main"

ppr_reduction_golden_test(
    name = "list_diff_reduction_golden_test_lang",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_seed_file = "golden_reduced_seed.c",
    golden_reduced_variant_file = "golden_reduced_variant.c",
    log_file = "reduction_golden_test.log",
    other_flags = {
        "--enable-diff-ddmin": "false",
        "--enable-diff-slicer": "true",
        "--lang": "c",
    },
    perses_bin = PERSES_LIST_DIFF_REDUCER_BIN,
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority-dfs",
    seed_file = "seed.unknown_language",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.unknown_language",
)
