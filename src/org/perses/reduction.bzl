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
        code_format = None):
    if "/" in source_file:
        fail("The source file should be in the current folder.")
    if "/" in test_script:
        fail("The test script should be in the current folder.")

    result_file = result_file or "reduced_result_%s" % source_file
    statistics_file = statistics_file or "%s_statistics.txt" % name
    progress_dump_file = progress_dump_file or "%s_progress.txt" % name
    if enable_query_caching == None:
        enable_query_caching = True
    if enable_edit_caching == None:
        enable_edit_caching = True
    if enable_token_slicer == None:
        enable_token_slicer = False
    if enable_tree_slicer == None:
        enable_tree_slicer = False
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
        "--enable-token-slicer %s" % ("true" if enable_token_slicer else "false"),
        "--enable-tree-slicer %s" % ("true" if enable_tree_slicer else "false"),
    ]
    if (code_format):
        args.append("--code-format %s" % code_format)
    native.genrule(
        name = name,
        outs = [result_file, statistics_file, progress_dump_file],
        srcs = [source_file, test_script],
        tools = [perses_bin],
        cmd = " ".join(args),
    )
