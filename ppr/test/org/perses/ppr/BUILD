load("//benchmark:benchmark.bzl", "sanity_test")
load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

PPR_REDUCER_BIN = "//ppr/src/org/perses/ppr:main"

sanity_test(
    name = "sanity_test",
    source_files = [
        "seed.c",
        "variant.c",
    ],
    test_script = "r.sh",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_all_reducers",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_all_reducers.c",
    golden_reduced_variant_file = "golden_reduced_variant_all_reducers.c",
    log_file = "reduction_golden_test_all_reducers.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "true",
        "--min-commonality": "true",
        "--enable-mirror": "false",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_all_reducers_mirror",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "all_reducers_mirror_golden_progress.txt",
    golden_reduced_seed_file = "golden_reduced_seed_all_reducers_mirror.c",
    golden_reduced_variant_file = "golden_reduced_variant_all_reducers_mirror.c",
    log_file = "reduction_golden_test_all_reducers_mirror.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "true",
        "--min-commonality": "true",
        "--enable-mirror": "true",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
        "--append-to-progress-dump-file": "true",
    },
    perses_bin = PPR_REDUCER_BIN,
    progress_dump_file = "all_reducers_mirror_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_tree_diff_reducer",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_tree_diff.c",
    golden_reduced_variant_file = "golden_reduced_variant_tree_diff.c",
    log_file = "reduction_golden_test_tree_diff_reducer.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "false",
        "--min-commonality": "false",
        "--enable-mirror": "false",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_tree_diff_reducer_mirror",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_tree_diff_mirror.c",
    golden_reduced_variant_file = "golden_reduced_variant_tree_diff_mirror.c",
    log_file = "reduction_golden_test_tree_diff_reducer_mirror.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "false",
        "--min-commonality": "false",
        "--enable-mirror": "true",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_list_diff_reducer",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_list_diff.c",
    golden_reduced_variant_file = "golden_reduced_variant_list_diff.c",
    log_file = "reduction_golden_test_list_diff_reducer.log",
    other_flags = {
        "--min-tdiff": "false",
        "--min-ldiff": "true",
        "--min-commonality": "false",
        "--enable-mirror": "false",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_list_diff_reducer_mirror",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_list_diff_mirror.c",
    golden_reduced_variant_file = "golden_reduced_variant_list_diff_mirror.c",
    log_file = "reduction_golden_test_list_diff_reducer_mirror.log",
    other_flags = {
        "--min-tdiff": "false",
        "--min-ldiff": "true",
        "--min-commonality": "false",
        "--enable-mirror": "true",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_commonality_reducer",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_commonality.c",
    golden_reduced_variant_file = "golden_reduced_variant_commonality.c",
    log_file = "reduction_golden_test_commonality_reducer.log",
    other_flags = {
        "--min-tdiff": "false",
        "--min-ldiff": "false",
        "--min-commonality": "true",
        "--enable-mirror": "false",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_commonality_reducer_mirror",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_commonality_mirror.c",
    golden_reduced_variant_file = "golden_reduced_variant_commonality_mirror.c",
    log_file = "reduction_golden_test_commonality_reducer_mirror.log",
    other_flags = {
        "--min-tdiff": "false",
        "--min-ldiff": "false",
        "--min-commonality": "true",
        "--enable-mirror": "true",
        "--call-formatter": "false",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

# test formatter
ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_all_reducers_mirror_formatter",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_all_reducers_mirror_formatter.c",
    golden_reduced_variant_file = "golden_reduced_variant_all_reducers_mirror_formatter.c",
    log_file = "reduction_golden_test_all_reducers_mirror_formatter_disabled.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "true",
        "--min-commonality": "true",
        "--enable-mirror": "true",
        "--call-formatter": "true",
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

# test other code formats
ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_all_reducers_mirror_code_format_single_token_per_line",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_all_reducers_mirror_code_format_single_token_per_line.c",
    golden_reduced_variant_file = "golden_reduced_variant_all_reducers_mirror_code_format_single_token_per_line.c",
    log_file = "reduction_golden_test_all_reducers_mirror_code_format_single_token_per_line.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "true",
        "--min-commonality": "true",
        "--enable-mirror": "true",
        "--call-formatter": "false",
        "--code-format": "SINGLE_TOKEN_PER_LINE",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

ppr_reduction_golden_test(
    name = "ppr_reduction_golden_test_all_reducers_mirror_code_format_orig_format",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_reduced_seed_file = "golden_reduced_seed_all_reducers_mirror_code_format_orig_format.c",
    golden_reduced_variant_file = "golden_reduced_variant_all_reducers_mirror_code_format_orig_format.c",
    log_file = "reduction_golden_test_all_reducers_mirror_code_format_orig_format.log",
    other_flags = {
        "--min-tdiff": "true",
        "--min-ldiff": "true",
        "--min-commonality": "true",
        "--enable-mirror": "true",
        "--call-formatter": "false",
        "--code-format": "ORIG_FORMAT",
    },
    perses_bin = PPR_REDUCER_BIN,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed.c",
    test_script = "r.sh",
    thread_count = 1,
    variant_file = "variant.c",
)

sh_test(
    name = "check_fixpoint_iterations_are_printed",
    srcs = ["ppr_reduction_log_test.sh"],
    args = [
        "$(location reduction_golden_test_all_reducers_mirror.log)",
    ],
    data = ["reduction_golden_test_all_reducers_mirror.log"],
)
