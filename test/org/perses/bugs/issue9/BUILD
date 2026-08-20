load("//test:test.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["T.java.txt"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_T.java.txt",
    other_flags = {
        # COMPACT_ORIG_FORMAT (not SINGLE_TOKEN_PER_LINE): the seed contains `1 << 2`, whose `<<`
        # the Java lexer splits into two `<` tokens. One-token-per-line would render them as `<`
        # newline `<`, i.e. `< <`, which does not compile, so the re-rendered program fails the
        # per-reducer (Layer-2) sanity check. A compact format keeps `<<` intact.
        "--code-format": "COMPACT_ORIG_FORMAT",
        "--lang": "java",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "T.java.txt",
    test_script = "r.sh",
)

# The same input as above, but deliberately given the WRONG code format (SINGLE_TOKEN_PER_LINE),
# which renders `1 << 2`'s `<<` as `< <` and so fails the per-reducer (Layer-2) sanity check. This
# exercises adaptive code-format selection: the driver detects the failure, searches the language's
# allowed formats, switches to COMPACT_ORIG_FORMAT (emitting an adhoc message captured in the
# progress dump), and continues -- so a wrong --code-format is self-corrected instead of aborting.
# The reduced output ends up in the adapted (compact) format.
reduction_golden_test(
    name = "reduction_golden_test_with_adaptive_code_format",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress_with_adaptive_code_format.txt",
    golden_reduced_file = "golden_reduced_T.java_with_adaptive_code_format.txt",
    other_flags = {
        "--code-format": "SINGLE_TOKEN_PER_LINE",
        "--lang": "java",
    },
    progress_dump_file = "reduction_progress_with_adaptive_code_format.txt",
    reduction_algorithm = "node_priority",
    source_file = "T.java.txt",
    test_script = "r.sh",
)
