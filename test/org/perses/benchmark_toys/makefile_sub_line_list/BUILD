load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["Makefile"],
    test_script = "r.sh",
)

# Demonstrates SUB-LINE reduction: every source is on one `SRCS = ...` line, and only keep.c is
# needed. The word-level grammar makes each filename an individually-deletable token, so the unneeded
# entries are dropped from the line -- which a line-at-a-time grammar could not do.
reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_progress.txt",
    golden_reduced_file = "golden_reduced_Makefile",
    other_flags = {
        "--code-format": "ORIG_FORMAT",
    },
    reduction_algorithm = "node_priority",
    source_file = "Makefile",
    test_script = "r.sh",
)
