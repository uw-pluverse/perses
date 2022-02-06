load("//test/org/perses:test.bzl", "golden_test")
load(
    "//src/org/perses:reduction.bzl",
    "DEFAULT_MAIN_REDUCTION_ALGORITHM",
    "DEFAULT_PERSES_BIN",
    "reduce",
)

def sanity_test(name, source_files, test_script):
    script = "%s_sanity_test.sh" % name
    genrule_name = "%s_copy_script" % name
    native.genrule(
        name = genrule_name,
        outs = [script],
        srcs = ["//benchmark:sanity_test"],
        cmd = "cp $(location //benchmark:sanity_test) $(location %s)" % script,
    )

    args = ["$(location %s)" % test_script]
    for source_file in source_files:
        args.append("$(location %s)" % source_file)

    data = [test_script]
    for source_file in source_files:
        data.append(source_file)

    native.sh_test(
        name = name,
        srcs = [script],
        args = args,
        data = data,
    )

# TODO: add a golden test for the reducers.
def reduction_golden_test(
        name,
        source_file,
        test_script,
        golden_reduced_file,
        reduction_algorithm = DEFAULT_MAIN_REDUCTION_ALGORITHM,
        statistics_file = None,
        progress_dump_file = None,
        golden_progress_file = None,
        enable_query_caching = None,
        enable_edit_caching = None,
        thread_count = None,
        log_file = None,
        other_flags = None,
        perses_bin = DEFAULT_PERSES_BIN,
        deps = None):
    if "/" in source_file:
        fail("The source file should be in the current folder.")
    if "/" in test_script:
        fail("The test script should be in the current folder.")

    genrule_reduction = "%s_reduction" % name
    output_dir = "result_%s_%s_%s" % (name, reduction_algorithm, source_file)
    result_file = "%s/%s" % (output_dir, source_file)

    if other_flags == None:
        other_flags = {}

    if "--code-format" not in other_flags:
        other_flags["--code-format"] = "COMPACT_ORIG_FORMAT"

    reduce(
        name = genrule_reduction,
        reduction_algorithm = reduction_algorithm,
        source_file = source_file,
        test_script = test_script,
        thread_count = thread_count,
        output_dir = output_dir,
        statistics_file = statistics_file,
        progress_dump_file = progress_dump_file,
        enable_query_caching = enable_query_caching,
        enable_edit_caching = enable_edit_caching,
        log_file = log_file,
        other_flags = other_flags,
        perses_bin = perses_bin,
        deps = deps,
    )

    result_file_group = "result_file_group_%s" % name
    native.filegroup(
        name = result_file_group,
        srcs = [result_file],
    )

    golden_test(
        name = name,
        golden_file = golden_reduced_file,
        test_file = result_file_group,
    )

    if golden_progress_file:
        if not progress_dump_file:
            fail("The golden_progress_file and progress_file must be specified together.")
        golden_test(
            name = "%s_progress_test" % name,
            golden_file = golden_progress_file,
            test_file = progress_dump_file,
        )
