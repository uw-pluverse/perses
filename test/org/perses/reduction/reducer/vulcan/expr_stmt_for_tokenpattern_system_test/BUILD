load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--on-demand-fine-grit-reducer-annotations": "org.perses.reduction.reducer.vulcan.pattern.LocalExhaustivePatternReducer\\$$META",
        "--verbosity": "FINE",
    },
    perses_bin = "//src/org/perses:perses",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    # A fast, compiler-free (grep-based) example that uses the token pattern reducer directly as the
    # main reduction algorithm. Every other reducer is disabled -- latra and trec (trec is off by
    # default), the top-down regular-rule/kleene reduction, and mimir -- both to keep the example
    # focused on the token pattern reducer and because those reducers re-parse the program, which the
    # token pattern reducer can make unparsable under a purely grep-based interestingness test.
    name = "grep_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_grep_reduction_progress.txt",
    golden_reduced_file = "golden_grep_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--enable-mimir-for-regular-node": "false",
        "--enable-reducing-kleene-and-optional-node": "false",
        "--enable-reducing-regular-rule-node": "false",
        "--enable-top-down-reduction": "false",
    },
    progress_dump_file = "grep_reduction_progress.txt",
    reduction_algorithm = "token_pattern_reducer",
    source_file = "t.c",
    test_script = "grep_r.sh",
)

reduction_golden_test(
    # Runs the local-exhaustive pattern reducer concurrently (thread_count > 1) to exercise its
    # concurrent list-minimizer path. It pins only the reduced result -- reusing the sequential
    # golden, which asserts the concurrent result is deterministic and identical to the sequential
    # one -- and not the progress trace, which is non-deterministic under concurrency.
    name = "concurrent_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_grep_reduced_t.c",
    other_flags = {
        "--enable-latra": "false",
        "--enable-mimir-for-regular-node": "false",
        "--enable-reducing-kleene-and-optional-node": "false",
        "--enable-reducing-regular-rule-node": "false",
        "--enable-top-down-reduction": "false",
    },
    perses_bin = "//src/org/perses:perses",
    reduction_algorithm = "token_pattern_reducer",
    source_file = "t.c",
    test_script = "grep_r.sh",
    thread_count = 3,
)
