load("//test:test.bzl", "golden_test")

EVENT_DIFF_TREE_DUMP_MAIN = "//test/org/perses/analyzer/differential:EventDiffTreeModelDumpMain"

def event_diff_golden_test(name, golden_file, run_yaml, extra_deps = None):
    genrule_name = name + "_gen"
    output_file_name = name + "_actual_output.txt"
    args = [
        "$(location %s)" % EVENT_DIFF_TREE_DUMP_MAIN,
        "--input",
        "$(location %s)" % run_yaml,
        "--output",
        "$(location %s)" % output_file_name,
    ]
    if not extra_deps:
        extra_deps = []

    native.genrule(
        name = genrule_name,
        srcs = [
            run_yaml,
        ] + extra_deps,
        outs = [
            output_file_name,
        ],
        tools = [
            EVENT_DIFF_TREE_DUMP_MAIN,
        ],
        cmd = " ".join(args),
    )
    golden_test(
        name = name,
        golden_file = golden_file,
        test_file = output_file_name,
    )
