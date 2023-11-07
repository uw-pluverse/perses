load("//test/org/perses:test.bzl", "golden_test")
load("//src/org/perses:reduction.bzl", "reduce")

def ppr_reduction_golden_test(
        name,
        reduction_algorithm,
        seed_file,
        variant_file,
        test_script,
        golden_reduced_seed_file,
        golden_reduced_variant_file,
        perses_bin,
        statistics_file = None,
        progress_dump_file = None,
        golden_progress_file = None,
        enable_query_caching = None,
        enable_edit_caching = None,
        thread_count = None,
        log_file = None,
        other_flags = None):
    if "/" in seed_file:
        fail("The seed file should be in the current folder.")
    if "/" in variant_file:
        fail("The variant file should be in the current folder.")
    if "/" in test_script:
        fail("The test script should be in the current folder.")

    genrule_reduction = "%s_reduction" % name
    output_dir = "result_%s_%s_%s_%s" % (name, reduction_algorithm, seed_file, variant_file)
    result_seed_file = "%s/%s" % (output_dir, seed_file)
    result_variant_file = "%s/%s" % (output_dir, variant_file)

    if other_flags == None:
        other_flags = {}

    other_flags["--variant"] = "$(location %s)" % variant_file

    # Reparsing changes the unique id of each Token and affects the matching, thus we disable it.
    other_flags["--reparse-each-iteration"] = "false"

    reduce(
        name = genrule_reduction,
        reduction_algorithm = reduction_algorithm,
        source_file = seed_file,
        test_script = test_script,
        thread_count = thread_count,
        output_dir = output_dir,
        names_of_other_files_in_output_dir = [variant_file],
        statistics_file = statistics_file,
        progress_dump_file = progress_dump_file,
        enable_query_caching = enable_query_caching,
        enable_edit_caching = enable_edit_caching,
        log_file = log_file,
        other_flags = other_flags,
        perses_bin = perses_bin,
        deps = [variant_file],
    )

    golden_test(
        name = "%s_seed" % name,
        golden_file = golden_reduced_seed_file,
        test_file = result_seed_file,
    )

    golden_test(
        name = "%s_variant" % name,
        golden_file = golden_reduced_variant_file,
        test_file = result_variant_file,
    )

    if golden_progress_file:
        if not progress_dump_file:
            fail("The golden_progress_file and progress_file must be specified together.")
        golden_test(
            name = "%s_progress_test" % name,
            golden_file = golden_progress_file,
            test_file = progress_dump_file,
        )
