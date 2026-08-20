load(
    "@rules_java//java:defs.bzl",
    "java_binary",
    "java_library",
)
load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_library",
)

def copy(name, src, dest):
    native.genrule(
        name = name,
        outs = [
            dest,
        ],
        srcs = [
            src,
        ],
        cmd = "cp $< $@",
    )

def kt_binary_for_genrule(
        name,
        srcs,
        main_class,
        deps,
        data = None,
        jvm_flags = None,
        args = None):
    lib_name = "kt_aux_lib_" + name
    if not data:
        data = []
    kt_jvm_library(
        name = lib_name,
        srcs = srcs,
        deps = deps,
        data = data,
    )
    if not jvm_flags:
        jvm_flags = []
    if not args:
        args = []
    java_binary(
        name = name,
        main_class = main_class,
        runtime_deps = [
            lib_name,
        ],
        jvm_flags = jvm_flags,
        args = args,
    )

DEFAULT_PERSES_BIN = "//src/org/perses:perses"
DEFAULT_MAIN_REDUCTION_ALGORITHM = "node_priority"

def reduce_multiple_files(
        name,
        reduction_algorithm,
        source_files,
        test_script,
        output_dir = None,
        names_of_other_files_in_output_dir = None,
        expected_deleted_files = None,
        enable_query_caching = None,
        enable_edit_caching = None,
        enable_token_reducer = None,
        enable_vulcan = None,
        statistics_file = None,
        progress_dump_file = None,
        thread_count = None,
        verbosity = None,
        log_file = None,
        call_formatter = None,
        other_flags = None,
        extra_output_files = None,
        list_minimizer_profile = None,
        perses_bin = DEFAULT_PERSES_BIN,
        cmd_deps = None,
        deps = None):
    """Reduces one or more source files together against a single interestingness test.

    Passes one --input-file flag per file; with more than one file Perses dispatches to its
    multi-file reduction path. When output_dir is set, every reduced file lands in it and is declared
    as a genrule output -- except files listed in expected_deleted_files, which Perses' file-deletion
    phase removes from the result folder, so they must NOT be declared as outputs. [reduce] is the
    single-file special case of this macro.
    """
    expected_deleted_files = expected_deleted_files or []
    for source_file in source_files:
        # Source files may live in subdirectories of this package (e.g. "src/a.c"): the reducer keeps
        # each file at its path relative to the test script's directory. Absolute or parent-escaping
        # paths are rejected because they would fall outside that root.
        if source_file.startswith("/") or source_file.startswith("../") or "/../" in source_file:
            fail("The source file must be within the current folder: " + source_file)
    if "/" in test_script:
        fail("The test script should be in the current folder.")
    if output_dir == None and names_of_other_files_in_output_dir != None:
        fail("output_dir cannot be None if names_of_other_files_in_output_dir is not None.")

    thread_count = thread_count or 1  # for determinism
    stdout_file = "%s.stdout.txt" % name

    args = [
        "$(location %s)" % perses_bin,
        "--test-script $(location %s)" % test_script,
    ]
    for source_file in source_files:
        args.append("--input-file $(location %s)" % source_file)
    args.append("--alg %s" % reduction_algorithm)
    args.append("--threads %s" % thread_count)
    args.append("--hide-timestamps true")

    outs = []
    if enable_query_caching != None:
        args.append("--query-caching %s" % ("true" if enable_query_caching else "false"))
    if enable_edit_caching != None:
        args.append("--edit-caching %s" % ("true" if enable_edit_caching else "false"))

    if enable_token_reducer != None:
        args.append("--enable-trec %s" % ("true" if enable_token_reducer else "false"))
    else:
        args.append("--enable-trec false")

    if enable_vulcan != None:
        args.append("--enable-vulcan %s" % ("true" if enable_vulcan else "false"))
    else:
        args.append("--enable-vulcan false")

    if call_formatter != None:
        args.append("--call-formatter %s" % ("true" if call_formatter else "false"))
    if progress_dump_file:
        args.append("--progress-dump-file $(location %s)" % progress_dump_file)
        outs.append(progress_dump_file)
    if statistics_file:
        args.append("--stat-dump-file $(location %s)" % statistics_file)
        outs.append(statistics_file)
    if list_minimizer_profile:
        args.append("--profile-list-minimizer $(location %s)" % list_minimizer_profile)
        outs.append(list_minimizer_profile)

    if output_dir != None:
        # All reduced files land in output_dir; derive it from the first file's result location by
        # stripping that file's (possibly nested) relative path. source_files[0] may sit in a
        # subdirectory (e.g. "src/main.c"), so peel off one path component per "/" plus the file name
        # itself -- i.e. (number of "/" + 1) dirname calls -- to land back on output_dir.
        main_result_file = "%s/%s" % (output_dir, source_files[0])
        output_dir_location = "$(location %s)" % main_result_file
        for _ in range(source_files[0].count("/") + 1):
            output_dir_location = "$$(dirname %s)" % output_dir_location
        args.append("--output-dir %s" % output_dir_location)
        for source_file in source_files:
            # A file Perses is expected to delete is gone from the result folder, so it cannot be a
            # declared genrule output (bazel would fail on the missing output).
            if source_file not in expected_deleted_files:
                outs.append("%s/%s" % (output_dir, source_file))
        if names_of_other_files_in_output_dir:
            for file_name in names_of_other_files_in_output_dir:
                outs.append("%s/%s" % (output_dir, file_name))

    if verbosity:
        args.append("--verbosity %s" % verbosity)

    if other_flags:
        for (key, value) in other_flags.items():
            args.append(key)
            args.append(value)
    if extra_output_files:
        outs += extra_output_files

    if log_file:
        args.append("&>")
        args.append("$(location %s)" % log_file)
        outs.append(log_file)
    else:
        args.append("&>")
        args.append("$(location %s)" % stdout_file)
        outs.append(stdout_file)

    srcs = list(source_files) + [test_script]

    if cmd_deps:  # The flags --deps
        srcs.append(cmd_deps)
        args.append("--deps $(location %s)" % cmd_deps)
    if deps:  # This is the general deps which do not require to be specified in --deps
        srcs += deps
    native.genrule(
        name = name,
        outs = outs,
        srcs = srcs,
        tools = [perses_bin],
        cmd = " ".join(args),
    )

def reduce(
        name,
        reduction_algorithm,
        source_file,
        test_script,
        output_dir = None,
        names_of_other_files_in_output_dir = None,
        enable_query_caching = None,
        enable_edit_caching = None,
        enable_token_reducer = None,
        enable_vulcan = None,
        statistics_file = None,
        progress_dump_file = None,
        thread_count = None,
        verbosity = None,
        log_file = None,
        call_formatter = None,
        other_flags = None,
        extra_output_files = None,
        list_minimizer_profile = None,
        perses_bin = DEFAULT_PERSES_BIN,
        cmd_deps = None,
        deps = None):
    """Reduces a single source file: the one-file special case of [reduce_multiple_files]."""
    reduce_multiple_files(
        name = name,
        reduction_algorithm = reduction_algorithm,
        source_files = [source_file],
        test_script = test_script,
        output_dir = output_dir,
        names_of_other_files_in_output_dir = names_of_other_files_in_output_dir,
        enable_query_caching = enable_query_caching,
        enable_edit_caching = enable_edit_caching,
        enable_token_reducer = enable_token_reducer,
        enable_vulcan = enable_vulcan,
        statistics_file = statistics_file,
        progress_dump_file = progress_dump_file,
        thread_count = thread_count,
        verbosity = verbosity,
        log_file = log_file,
        call_formatter = call_formatter,
        other_flags = other_flags,
        extra_output_files = extra_output_files,
        list_minimizer_profile = list_minimizer_profile,
        perses_bin = perses_bin,
        cmd_deps = cmd_deps,
        deps = deps,
    )
