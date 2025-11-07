load("//benchmark:benchmark.bzl", "sanity_test")
load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")

PPR_REDUCER_BIN = "//ppr/src/org/perses/ppr:main"

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_commonality_reducer",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed.c",
    golden_reduced_variant_file = "golden_reduced_variant.c",
    log_file = "reduction_golden_test.log",
    other_flags = {
        "--min-tdiff": "false",
        "--min-ldiff": "false",
        "--min-commonality": "true",
        "--enable-mirror": "false",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "node_priority-dfs",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)
