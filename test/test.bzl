load("@rules_shell//shell:sh_binary.bzl", "sh_binary")
load("@rules_shell//shell:sh_test.bzl", "sh_test")
load(
    "//:perses.bzl",
    "DEFAULT_MAIN_REDUCTION_ALGORITHM",
    "DEFAULT_PERSES_BIN",
    "copy",
    "reduce",
    "reduce_multiple_files",
)

def golden_test(name, golden_file, test_file):
    rule_cp_diff_sh = "%s_copy_diff_script" % name
    diff_script = "%s_diff.sh" % name

    orig_diff_script = "//test/org/perses:diff.sh"
    copy(
        name = rule_cp_diff_sh,
        src = orig_diff_script,
        dest = diff_script,
    )

    sh_test(
        name = name,
        srcs = [diff_script],
        args = [
            "$(location %s)" % golden_file,
            "$(location %s)" % test_file,
        ],
        data = [
            golden_file,
            test_file,
        ],
    )

    rule_cp_copy_sh = "%s_copy_copy_script" % name
    copy_script = "%s_copy.sh" % name
    orig_copy_script = "//test/org/perses:copy.sh"
    copy(
        name = rule_cp_copy_sh,
        src = orig_copy_script,
        dest = copy_script,
    )
    sh_binary(
        name = "%s_update" % name,
        srcs = [copy_script],
        data = [
            golden_file,
            test_file,
        ],
        tags = ["golden_file_update_target"],
        args = [
            "$(location %s)" % test_file,
            "$(location %s)" % golden_file,
        ],
    )

def cross_folder_golden_test(
        name,
        test_file_in_other_folders,
        golden_file):
    copy_genrule_name = name + "_copy_gen"
    test_file = name + "_test_file"

    copy(
        name = copy_genrule_name,
        src = test_file_in_other_folders,
        dest = test_file,
    )

    golden_test(
        name = name,
        golden_file = golden_file,
        test_file = test_file,
    )

def sanity_test(name, source_files, test_script):
    script = "%s_sanity_test.sh" % name
    genrule_name = "%s_copy_script" % name
    native.genrule(
        name = genrule_name,
        outs = [script],
        srcs = ["//test:sanity_test"],
        cmd = "cp $(location //test:sanity_test) $(location %s)" % script,
    )

    args = ["$(location %s)" % test_script]
    for source_file in source_files:
        args.append("$(location %s)" % source_file)

    data = [test_script]
    for source_file in source_files:
        data.append(source_file)

    sh_test(
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
        enable_token_reducer = None,
        enable_vulcan = None,
        thread_count = None,
        log_file = None,
        list_minimizer_profile = None,
        golden_list_minimizer_profile = None,
        golden_global_cache_file = None,
        other_flags = None,
        perses_bin = DEFAULT_PERSES_BIN,
        extra_output_files = None,
        cmd_deps = None,
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

    if golden_progress_file and not progress_dump_file:
        progress_dump_file = "_%s_by_default_progress.txt" % name

    if golden_list_minimizer_profile and not list_minimizer_profile:
        list_minimizer_profile = "_%s_list_minimizer_profile.txt" % name

    updated_global_cache_csv_file = name + "_updated_global_cache_file.csv"
    if golden_global_cache_file:
        if extra_output_files:
            extra_output_files = extra_output_files + [updated_global_cache_csv_file]
        else:
            extra_output_files = [updated_global_cache_csv_file]
        if deps:
            deps = deps + [golden_global_cache_file]
        else:
            deps = [golden_global_cache_file]
        other_flags["--global-caching"] = "true"
        other_flags["--global-cache-file"] = "$(location %s)" % golden_global_cache_file
        other_flags["--path-to-save-updated-global-cache"] = "$(location %s)" % updated_global_cache_csv_file

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
        enable_token_reducer = enable_token_reducer,
        enable_vulcan = enable_vulcan,
        log_file = log_file,
        list_minimizer_profile = list_minimizer_profile,
        other_flags = other_flags,
        perses_bin = perses_bin,
        cmd_deps = cmd_deps,
        extra_output_files = extra_output_files,
        deps = deps,
    )

    result_file_group = "result_file_group_%s" % name
    native.filegroup(
        name = result_file_group,
        srcs = [result_file],
    )

    if golden_global_cache_file:
        golden_test(
            name = "golden_test_on_global_cache_file_%s" % name,
            golden_file = golden_global_cache_file,
            test_file = updated_global_cache_csv_file,
        )

    golden_test(
        name = name,
        golden_file = golden_reduced_file,
        test_file = result_file_group,
    )

    if golden_progress_file:
        golden_test(
            name = "%s_progress_test" % name,
            golden_file = golden_progress_file,
            test_file = progress_dump_file,
        )
    if golden_list_minimizer_profile:
        if not list_minimizer_profile:
            fail("The golden_list_minimizer_profile and list_minimizer_profile must be specified together.")
        golden_test(
            name = "%s_list_minimizer_golden_test" % name,
            golden_file = golden_list_minimizer_profile,
            test_file = list_minimizer_profile,
        )

def multi_file_reduction_golden_test(
        name,
        source_files,
        test_script,
        golden_reduced_files,
        golden_deleted_files = None,
        reduction_algorithm = DEFAULT_MAIN_REDUCTION_ALGORITHM,
        enable_query_caching = None,
        enable_edit_caching = None,
        enable_token_reducer = None,
        enable_vulcan = None,
        thread_count = None,
        progress_dump_file = None,
        golden_progress_file = None,
        log_file = None,
        other_flags = None,
        perses_bin = DEFAULT_PERSES_BIN,
        deps = None):
    """Reduces source_files together and golden-tests each surviving reduced file.

    golden_deleted_files lists the source_files Perses' file-deletion phase is expected to remove;
    they are not declared as outputs and not golden-tested individually (use golden_progress_file to
    pin the deletion behavior). golden_reduced_files is parallel to the SURVIVING files -- the
    source_files not in golden_deleted_files, in order.
    """
    golden_deleted_files = golden_deleted_files or []
    surviving_files = [f for f in source_files if f not in golden_deleted_files]
    if len(surviving_files) != len(golden_reduced_files):
        fail("golden_reduced_files must be parallel to the surviving (non-deleted) source files.")

    if other_flags == None:
        other_flags = {}
    if "--code-format" not in other_flags:
        other_flags["--code-format"] = "COMPACT_ORIG_FORMAT"

    if golden_progress_file and not progress_dump_file:
        progress_dump_file = "_%s_by_default_progress.txt" % name

    genrule_reduction = "%s_reduction" % name
    output_dir = "result_%s_%s" % (name, reduction_algorithm)

    reduce_multiple_files(
        name = genrule_reduction,
        reduction_algorithm = reduction_algorithm,
        source_files = source_files,
        test_script = test_script,
        output_dir = output_dir,
        expected_deleted_files = golden_deleted_files,
        thread_count = thread_count,
        enable_query_caching = enable_query_caching,
        enable_edit_caching = enable_edit_caching,
        enable_token_reducer = enable_token_reducer,
        enable_vulcan = enable_vulcan,
        progress_dump_file = progress_dump_file,
        log_file = log_file,
        other_flags = other_flags,
        perses_bin = perses_bin,
        deps = deps,
    )

    for i in range(len(surviving_files)):
        source_file = surviving_files[i]
        result_file = "%s/%s" % (output_dir, source_file)

        # source_file may contain "/" (a file in a subdirectory); target names cannot, so flatten
        # both "/" and "." into "_" when deriving the per-file target names.
        sanitized_source_file = source_file.replace("/", "_").replace(".", "_")
        result_file_group = "result_file_group_%s_%s" % (name, sanitized_source_file)
        native.filegroup(
            name = result_file_group,
            srcs = [result_file],
        )
        golden_test(
            name = "%s_%s_golden_test" % (name, sanitized_source_file),
            golden_file = golden_reduced_files[i],
            test_file = result_file_group,
        )

    if golden_progress_file:
        golden_test(
            name = "%s_progress_test" % name,
            golden_file = golden_progress_file,
            test_file = progress_dump_file,
        )
