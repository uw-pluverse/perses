def reduce(
        name,
        reduction_algorithm,
        source_file,
        test_script,
        enable_query_caching = None,
        enable_edit_caching = None,
        result_file = None,
        statistics_file = None,
        progress_dump_file = None,
        thread_count = None,
        keep_orig_format = None):
    if "/" in source_file:
        fail("The source file should be in the current folder.")
    if "/" in test_script:
        fail("The test script should be in the current folder.")

    result_file = result_file or "reduced_result_%s" % source_file
    statistics_file = statistics_file or "statistics_%s.txt" % source_file
    progress_dump_file = progress_dump_file or "progress_%s.txt" % source_file
    if enable_query_caching == None:
        enable_query_caching = True
    if enable_edit_caching == None:
        enable_edit_caching = True
    thread_count = thread_count or 1  # for determinism
    perses_bin = "//src/org/perses:perses"
    args = [
        "$(location %s)" % perses_bin,
        "--test-script $(location %s)" % test_script,
        "--input-file $(location %s)" % source_file,
        "--alg %s" % reduction_algorithm,
        "--threads %s" % thread_count,
        "--fixpoint true",
        "--output-file $(location %s)" % result_file,
        "--stat-dump-file $(location %s)" % statistics_file,
        "--progress-dump-file $(location %s)" % progress_dump_file,
        "--query-caching %s" % ("true" if enable_query_caching else "false"),
        "--edit-caching %s" % ("true" if enable_edit_caching else "false"),
    ]
    if (keep_orig_format):
        args.append("--keep-orig-format %s" % ("true" if keep_orig_format else "false"))
    native.genrule(
        name = name,
        outs = [result_file, statistics_file, progress_dump_file],
        srcs = [source_file, test_script],
        tools = [perses_bin],
        cmd = " ".join(args),
    )
