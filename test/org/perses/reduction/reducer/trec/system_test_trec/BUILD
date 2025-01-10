load("//benchmark:benchmark.bzl", "reduction_golden_test")

reduction_golden_test(
    name = "trec_reduction_golden_test",
    golden_progress_file = "golden_reduction_with_trec_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--code-format": "ORIG_FORMAT",
        "--enable-trec": "true",
    },
    progress_dump_file = "progress_dump_trec.txt",
    source_file = "t.c",
    test_script = "r.sh",
)
