load("//test/org/perses:test.bzl", "golden_test")
load("//src/org/perses:reduction.bzl", "reduce")

def sanity_test(name, source_file, test_script):
    script = "%s_sanity_test.sh" % name
    genrule_name = "%s_copy_script" % name
    native.genrule(
        name = genrule_name,
        outs = [script],
        srcs = ["//benchmark:sanity_test"],
        cmd = "cp $(location //benchmark:sanity_test) $(location %s)" % script,
    )
    native.sh_test(
        name = name,
        srcs = [script],
        args = [
            "$(location %s)" % test_script,
            "$(location %s)" % source_file,
        ],
        data = [test_script, source_file],
    )

# TODO: add a golden test for the reducers.
def reduction_golden_test(
        name,
        reduction_algorithm,
        source_file,
        test_script,
        golden_reduced_file,
        statistics_file = None,
        progress_dump_file = None,
        golden_progress_file = None):
    if "/" in source_file:
        fail("The source file should be in the current folder.")
    if "/" in test_script:
        fail("The test script should be in the current folder.")

    genrule_reduction = "%s_reduction" % name
    result_file = "result_%s_%s_%s" % (name, reduction_algorithm, source_file)

    reduce(
        name = genrule_reduction,
        reduction_algorithm = reduction_algorithm,
        source_file = source_file,
        test_script = test_script,
        thread_count = 1,
        result_file = result_file,
        statistics_file = statistics_file,
        progress_dump_file = progress_dump_file,
        code_format = "COMPACT_ORIG_FORMAT"
    )

    golden_test(
        name = name,
        golden_file = golden_reduced_file,
        test_file = result_file,
    )

    if golden_progress_file:
        if not progress_dump_file:
            fail("The golden_progress_file and progress_file must be specified together.")
        golden_test(
            name = "%s_progress_test" % name,
            golden_file = golden_progress_file,
            test_file = progress_dump_file,
        )
