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
        enable_token_slicer = None,
        enable_tree_slicer = None,
        code_format = None,
        verbosity = None,
        log_file = None,
        call_formatter = None):
    if "/" in source_file:
        fail("The source file should be in the current folder.")
    if "/" in test_script:
        fail("The test script should be in the current folder.")

    result_file = result_file or "reduced_%s_result_%s" % (name, source_file)
    statistics_file = statistics_file or "%s_statistics.txt" % name
    progress_dump_file = progress_dump_file or "%s_progress.txt" % name
    if enable_token_slicer == None:
        enable_token_slicer = False
    if enable_tree_slicer == None:
        enable_tree_slicer = False
    thread_count = thread_count or 1  # for determinism
    perses_bin = "//src/org/perses:perses"
    stdout_file = "%s.stdout.txt" % name

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
        "--enable-token-slicer %s" % ("true" if enable_token_slicer else "false"),
        "--enable-tree-slicer %s" % ("true" if enable_tree_slicer else "false"),
    ]

    if enable_query_caching != None:
        args.append("--query-caching %s" % ("true" if enable_query_caching else "false"))
    if enable_edit_caching != None:
        args.append("--edit-caching %s" % ("true" if enable_edit_caching else "false"))
    if call_formatter != None:
        args.append("--call-formatter %s" % ("true" if call_formatter else "false"))
    args.append("&>")
    args.append("$(location %s)" % stdout_file)

    outs = [result_file, statistics_file, progress_dump_file, stdout_file]
    if (code_format):
        args.append("--code-format %s" % code_format)
    if (verbosity):
        args.append("--verbosity %s" % verbosity)
    if (log_file):
        args.append("&> $(location %s)" % log_file)
        outs.append(log_file)
    native.genrule(
        name = name,
        outs = outs,
        srcs = [source_file, test_script],
        tools = [perses_bin],
        cmd = " ".join(args),
    )
