load("//test:test.bzl", "reduction_golden_test", "sanity_test")

# Regression test for a bug that made the Dyck node reducer refuse to run.
#
# t.c's first line is a bare `@`, which the C lexer has no token for. That one character used
# to disable the reducer entirely:
#
#   The reducer dyck_node_reducer is skipped, because the current program is not parsable by
#   its preferred parser facade BraceParenthesisDyckParserFacade.
#
# perses then reduced nothing -- output byte-identical to input, dead_a and dead_b intact --
# while exiting 0, so it looked like a successful 0% reduction rather than a reducer that
# never ran.
#
# The message was misleading: the Dyck tree parsed fine. What failed was measuring its
# *canonical* size. createInputRepresentation computed the canonical token count with the real
# C grammar, strictly, and that threw on the `@`; the exception surfaced as "not parsable".
# Counting is not parsing, so countTokensInString now always tolerates lexer errors.
#
# The same character class (`\` line-continuations, `#` directives) is what made the Dyck
# reducer skip 11 of the 20 strict-unparseable C benchmarks in
# benchmark_v2/benchmark_lists/taotie_2026_c_benchmark_list.txt, reporting 0% on each.

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

# The oracle only requires MARKER to survive, so a working Dyck reducer strips everything
# else -- including the `@` itself. If the bug returns, the reducer is skipped and the golden
# reduced file is the whole of t.c again, which this test catches.
reduction_golden_test(
    name = "dyck_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_dyck_progress.txt",
    golden_reduced_file = "golden_dyck_reduced_t.c",
    # --enable-trec is not listed here: the macro already emits it, and jcommander rejects a
    # repeated option ("Can only specify option --enable-trec once").
    other_flags = {
        "--enable-latra": "false",
    },
    reduction_algorithm = "dyck_node_reducer",
    source_file = "t.c",
    test_script = "r.sh",
)

filegroup(
    name = "files",
    srcs = [
        "r.sh",
        "t.c",
    ],
    visibility = ["//test:__subpackages__"],
)
