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

EVALUATED_MINIMIZER = "WINDOWED_SLICER"

# Each measurement writes into a directory named after its minimizer, so that the several
# minimizers of one problem cannot overwrite each other's fixed-name metrics files.
MINIMIZER_OUTPUT_DIR = METRICS_DIR + "/" + EVALUATED_MINIMIZER

QUERIES_JSONL = MINIMIZER_OUTPUT_DIR + "/queries.jsonl"

SUMMARY_JSONL = MINIMIZER_OUTPUT_DIR + "/summary.jsonl"

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
    # Pins the reducer name the statistics tables are keyed on. Those tables are process-wide, so
    # once several minimizers share a process this is what keeps their rows apart.
    golden_progress_file = "golden_evaluation_progress.txt",
    golden_reduced_file = "golden_evaluated_t.c",
    other_flags = {
        "--list-minimizer-microbenchmarking-mode": "EVALUATE",
        "--evaluation-microbenchmark": "$(location %s)" % RECORDED_MICROBENCHMARK,
        "--list-minimizers-to-evaluate": EVALUATED_MINIMIZER,
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

# The acceptance criterion of measuring several minimizers in one process: a minimizer measured
# alongside others must produce exactly what it produces alone.
#
# Nothing here is checked in. The two solo runs ARE the goldens, so there is no hand-maintained
# copy to drift -- the same reason the EVALUATE test above consumes the recording RECORD just made.
#
# Both orders are run, and that is what turns "passed by luck" into "there is no cross-run state":
# a single order can pass while a leak exists, if the first minimizer's behaviour happens to be a
# prefix of the second's.
#
# summary.jsonl must be diffed, not just queries.jsonl. A query-cache hit still reaches the
# listener, so a leak between measurements would leave the whole query trace intact and show up
# only in scriptExecutionCount -- which, under the --hide-timestamps that perses.bzl passes to
# every reduction genrule, is the sole cache-sensitive field that is not nulled.
METRICS_FILE_NAMES = [
    "queries.jsonl",
    "summary.jsonl",
]

# Each measures one minimizer per process, as the sweep used to do for every measurement; together
# they are the goldens the combined runs below are diffed against.
SOLO_EVALUATION_RUNS = {
    "solo_wdd": ["WDD"],
    "solo_cdd": ["CDD"],
}

COMBINED_EVALUATION_RUNS = {
    "wdd_then_cdd": [
        "WDD",
        "CDD",
    ],
    "cdd_then_wdd": [
        "CDD",
        "WDD",
    ],
}

[
    reduction_golden_test(
        name = "evaluate_%s" % name,
        extra_output_files = [
            "%s/%s/%s" % (name, minimizer, metrics)
            for minimizer in minimizers
            for metrics in METRICS_FILE_NAMES
        ],
        golden_reduced_file = "golden_evaluated_t.c",
        other_flags = {
            "--list-minimizer-microbenchmarking-mode": "EVALUATE",
            "--evaluation-microbenchmark": "$(location %s)" % RECORDED_MICROBENCHMARK,
            "--list-minimizers-to-evaluate": ",".join(minimizers),
            "--evaluation-output": "$(RULEDIR)/" + name,
        },
        source_file = "t.c",
        test_script = "r.sh",
        deps = [RECORDED_MICROBENCHMARK],
    )
    for name, minimizers in SOLO_EVALUATION_RUNS.items() + COMBINED_EVALUATION_RUNS.items()
]

[
    golden_test(
        name = "%s_%s_%s_matches_its_solo_run" % (
            combined_name,
            minimizer.lower(),
            metrics.split(".")[0],
        ),
        golden_file = "solo_%s/%s/%s" % (
            minimizer.lower(),
            minimizer,
            metrics,
        ),
        test_file = "%s/%s/%s" % (combined_name, minimizer, metrics),
    )
    for combined_name, minimizers in COMBINED_EVALUATION_RUNS.items()
    for minimizer in minimizers
    for metrics in METRICS_FILE_NAMES
]
