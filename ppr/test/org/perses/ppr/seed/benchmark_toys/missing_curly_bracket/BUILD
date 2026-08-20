load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")
load("//test:test.bzl", "sanity_test")

PERSES_SEED_REDUCER_BIN = "//ppr/src/org/perses/ppr/seed:main"

sanity_test(
    name = "sanity_test",
    source_files = [
        "seed.c",
        "variant.c",
    ],
    test_script = "r.sh",
)

ppr_reduction_golden_test(
    name = "seed_reduction_golden_test_missing_curly_bracket",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_seed_file = "golden_reduced_seed.c",
    golden_reduced_variant_file = "golden_reduced_variant.c",
    log_file = "reduction_golden_test.log",
    other_flags = {
    },
    perses_bin = PERSES_SEED_REDUCER_BIN,
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)
