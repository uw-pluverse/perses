# The record -> evaluate round trip: one reduction records a list-minimization problem, and a second
# invocation evaluates a minimizer against the problem the first one just produced. Both live here
# so the recorded problem is generated rather than checked in -- a change to what a recording
# contains cannot leave a stale copy behind, because there is no copy.
load("//test:test.bzl", "golden_test", "reduction_golden_test", "sanity_test")

# Guards RECORD mode end to end: a real reduction records list-minimization problems, and the
# goldens pin what a recording contains.
#
# The corpus is a directory tree, which a golden cannot diff, so this pins one problem instead of
# all of them -- the ranges of problem 000000 together with the program those ranges index into.
# Both are needed: ranges alone say nothing without the text they point at. The test script is
# pinned too -- a recorded folder without its oracle is not a problem anyone can evaluate.
#
# --alg token_slicer keeps the corpus small and its folder names predictable; without a pinned
# reducer the recorded set moves with any change to reducer scheduling.

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

RECORDED_MICROBENCHMARK = "recorded/000000/microbenchmark.yaml"

RECORDED_PROGRAM = "recorded/000000/input/t.c"

RECORDED_SCRIPT = "recorded/000000/input/r.sh"

# Exposed so the corpus-generator's test reads a microbenchmark.yaml perses actually wrote. A
# hand-written fixture would drift from the writer silently -- and the reader under test counts
# yaml markers rather than parsing, so drift would show up as a count of zero, not as a failure.
filegroup(
    name = "recorded_microbenchmark",
    srcs = [RECORDED_MICROBENCHMARK],
    visibility = ["//benchmark_v2/test:__pkg__"],
)

reduction_golden_test(
    name = "record_mode_golden_test",
    extra_output_files = [
        RECORDED_MICROBENCHMARK,
        RECORDED_PROGRAM,
        RECORDED_SCRIPT,
    ],
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--list-minimizer-microbenchmarking-mode": "RECORD",
        "--list-minimizer-microbenchmark-output": "$(RULEDIR)/recorded",
        # Below the default of 4, so a program this small still records.
        "--min-list-size-to-record": "1",
    },
    reduction_algorithm = "token_slicer",
    source_file = "t.c",
    test_script = "r.sh",
)

golden_test(
    name = "recorded_microbenchmark_golden_test",
    golden_file = "golden_microbenchmark.yaml",
    test_file = RECORDED_MICROBENCHMARK,
)

golden_test(
    name = "recorded_program_golden_test",
    golden_file = "golden_recorded_t.c",
    test_file = RECORDED_PROGRAM,
)

golden_test(
    name = "recorded_script_golden_test",
    golden_file = "golden_recorded_r.sh",
    test_file = RECORDED_SCRIPT,
)

METRICS_DIR = "metrics"

QUERIES_JSONL = METRICS_DIR + "/queries.jsonl"

SUMMARY_JSONL = METRICS_DIR + "/summary.jsonl"

# Both are goldened. Durations -- the only nondeterministic thing these files carry -- are reported
# as null under --hide-timestamps, which perses.bzl passes to every reduction genrule, so what is
# left is identity, counts, sizes and outcomes.
ALL_METRICS = [
    QUERIES_JSONL,
    SUMMARY_JSONL,
]

# EVALUATE consumes the problem the RECORD test above just produced, rather than a checked-in copy.
# That is the point of keeping both in one package: a change to what a recording contains cannot
# leave a stale hand-maintained microbenchmark.yaml behind, because there is no hand-maintained copy.
#
# The recorded program is byte-identical to t.c -- the first list a reduction minimizes is over the
# unreduced tree -- so the source file and test script here are the same ones RECORD ran on.
reduction_golden_test(
    name = "evaluate_mode_golden_test",
    extra_output_files = ALL_METRICS,
    golden_reduced_file = "golden_evaluated_t.c",
    other_flags = {
        "--list-minimizer-microbenchmarking-mode": "EVALUATE",
        "--evaluation-microbenchmark": "$(location %s)" % RECORDED_MICROBENCHMARK,
        "--evaluation-minimizer": "WINDOWED_SLICER",
        "--evaluation-output": "$(RULEDIR)/" + METRICS_DIR,
    },
    source_file = "t.c",
    test_script = "r.sh",
    deps = [RECORDED_MICROBENCHMARK],
)

# Pins the per-query trace: one record per property test, with what was attempted, where in the
# list, and how it turned out. This is what a change in a minimizer's search order shows up in.
golden_test(
    name = "queries_jsonl_golden_test",
    golden_file = "golden_queries.jsonl",
    test_file = QUERIES_JSONL,
)

golden_test(
    name = "summary_jsonl_golden_test",
    golden_file = "golden_summary.jsonl",
    test_file = SUMMARY_JSONL,
)
