load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

# t.c is deliberately not valid C (a top-level brace block), but its delimiters are balanced, so the
# reduction falls back from the C grammar to the tolerant Dyck grammar -- the ladder's only rung --
# instead of bailing out, and the adaptive facade there enables every delimiter kind because they all
# nest. See internal_doc/tolerant_grammar_fallback_design.md.
sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        # Pin the flag off: this test exercises the Dyck-grammar *spine* fallback, which is only
        # reached when the error-tolerant real-grammar rung is disabled (that rung is on by default
        # and, since it recovers almost anything, would otherwise win and shadow the Dyck spine).
        "--enable-error-tolerant-grammar": "false",
        "--fully-deterministic-mode": "true",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "t.c",
    test_script = "r.sh",
)
