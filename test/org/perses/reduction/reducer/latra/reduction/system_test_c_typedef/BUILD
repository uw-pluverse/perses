load("//benchmark:benchmark.bzl", "reduction_golden_test")

reduction_golden_test(
    name = "latra_reduction_golden_test_typedef",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--code-format": "ORIG_FORMAT",
        "--enable-latra": "true",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "FineGritLatraReducer",
    source_file = "t.c",
    test_script = "r.sh",
)
