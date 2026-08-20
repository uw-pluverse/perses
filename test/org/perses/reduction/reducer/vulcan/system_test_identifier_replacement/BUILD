load("//test:test.bzl", "reduction_golden_test")

reduction_golden_test(
    name = "reduce_c_program_with_identifier_replacement",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_with_identifier_replacement_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--code-format": "ORIG_FORMAT",
        "--on-demand-fine-grit-reducer-annotations": "org.perses.reduction.reducer.vulcan.IdentifierReplacementReducer\\$$META",
    },
    perses_bin = "//src/org/perses:perses",
    progress_dump_file = "progress_dump_identifier_replacement.txt",
    reduction_algorithm = "node_priority",
    source_file = "t.c",
    test_script = "r.sh",
)
