package(default_visibility = ["//test:__subpackages__"])

load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")
load("//src/org/perses:reduction.bzl", "reduce")

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

LOG_FILE = "reduction_golden_test.log"

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    log_file = LOG_FILE,
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

GREPPED_CACHE_SETTING_FILE = "grepped_query_cache_setting.txt"

genrule(
    name = "grep_cache_setting",
    srcs = [LOG_FILE],
    outs = [GREPPED_CACHE_SETTING_FILE],
    cmd = "grep --only-matching 'Cache setting:.*' $(location %s) > $(location %s)" % (LOG_FILE, GREPPED_CACHE_SETTING_FILE),
)

golden_test(
    name = "grep_cache_setting_golden_test",
    golden_file = "golden_grepped_query_cache_setting.txt",
    test_file = GREPPED_CACHE_SETTING_FILE,
)

GREPPED_CMD_KEY_VALUE_PAIRS_FILE = "grepped_cmd_key_value_pairs.txt"

genrule(
    name = "grep_command_line_option_key_value_pairs",
    srcs = [LOG_FILE],
    outs = [GREPPED_CMD_KEY_VALUE_PAIRS_FILE],
    cmd = "grep --only-matching 'The command-line options are:.*' $(location %s) > $(location %s)" % (LOG_FILE, GREPPED_CMD_KEY_VALUE_PAIRS_FILE),
)

golden_test(
    name = "grep_cmd_option_key_value_pairs_golden_test",
    golden_file = "golden_grepped_cmd_option_key_value_pairs.txt",
    test_file = GREPPED_CMD_KEY_VALUE_PAIRS_FILE,
)

GREPPED_NUMBER_OF_REMOVED_TOKENS = "grepped_number_of_removed_tokens.txt"

genrule(
    name = "grep_number_of_removed_tokens",
    srcs = [LOG_FILE],
    outs = [GREPPED_NUMBER_OF_REMOVED_TOKENS],
    cmd = "grep --only-matching 'Removed.*$$' $(location %s) > $(location %s)" % (LOG_FILE, GREPPED_NUMBER_OF_REMOVED_TOKENS),
)

golden_test(
    name = "grep_number_of_removed_tokens_golden_test",
    golden_file = "golden_grepped_number_of_removed_tokens.txt",
    test_file = GREPPED_NUMBER_OF_REMOVED_TOKENS,
)

# Note that token slicer checks syntactical validity when
# the program being reduced is small. So, it is not possible
# to get the 'world\n' as the final result.
reduction_golden_test(
    name = "grep_based_token_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_grep_based_reduction_progress.txt",
    golden_reduced_file = "golden_grep_based_reduced_t.c",
    other_flags = {
        "--enable-token-slicer": "true",
    },
    progress_dump_file = "grep_based_reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.c",
    test_script = "grep_based_r.sh",
)

reduction_golden_test(
    name = "grep_based_token_reduction_with_pass_level_cache_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_progress_file = "golden_grep_based_reduction_with_pass_level_caching_progress.txt",
    golden_reduced_file = "golden_grep_based_with_pass_level_caching_reduced_t.c",
    other_flags = {
        "--enable-token-slicer": "true",
        "--enable-line-slicer": "true",
        "--enable-tree-slicer": "true",
        "--pass-level-caching": "true",
    },
    progress_dump_file = "grep_based_reduction_with_pass_level_cache_progress.txt",
    reduction_algorithm = "concurrent_token_slicer",
    source_file = "t.c",
    test_script = "grep_based_r.sh",
)

sh_test(
    name = "check_fixpoint_iterations_are_printed",
    srcs = ["reduction_log_test.sh"],
    args = [
        "$(location reduction_golden_test.log)",
    ],
    data = ["reduction_golden_test.log"],
)

reduction_golden_test(
    name = "reduction_concurrent_token_slicer_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_reduced_t.c",
    log_file = "reduction_concurrent_token_slicer_golden_test.log",
    reduction_algorithm = "concurrent_token_slicer",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 3,
)

reduction_golden_test(
    name = "reduction_using_pristine_ddmin_for_reducing_kleene_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_using_pristine_ddmin_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_pristine_ddmin_t.c",
    other_flags = {
        "--default-delta-debugger-for-kleene": "PRISTINE",
    },
    progress_dump_file = "reduction_using_pristine_ddmin_for_reducing_kleene_progress.txt",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_using_probdd_for_reducing_kleene_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_using_probdd_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_probdd_t.c",
    other_flags = {
        "--default-delta-debugger-for-kleene": "PROBDD",
    },
    progress_dump_file = "reduction_using_probdd_for_reducing_kleene_progress.txt",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_concurrent_state_token_slicer_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_concurrent_state_token_slicer_reduced_t.c",
    log_file = "reduction_concurrent_state_token_slicer_golden_test.log",
    reduction_algorithm = "concurrent_state_token_slicer",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 5,
)

reduction_golden_test(
    name = "reduction_concurrent_ddmin_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_concurrent_ddmin_reduced_t.c",
    log_file = "reduction_concurrent_ddmin_golden_test.log",
    reduction_algorithm = "concurrent_state_ddmin",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 5,
)

reduction_golden_test(
    name = "reduction_ddmin_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_ddmin_reduced_t.c",
    log_file = "reduction_ddmin_golden_test.log",
    reduction_algorithm = "ddmin",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

sh_test(
    name = "token_slicer_log_should_print_the_correct_total_token_count",
    srcs = ["token_slicer_log_test.sh"],
    args = [
        "$(location reduction_concurrent_token_slicer_golden_test.log)",
    ],
    data = [
        "reduction_concurrent_token_slicer_golden_test.log",
    ],
)

name_reduce_with_formatter = "reduce_with_formatter"

output_dir_reduce_with_formatter = "output_dir_reduce_with_formatter"

reduce(
    name = name_reduce_with_formatter,
    call_formatter = True,
    enable_edit_caching = True,
    enable_query_caching = True,
    output_dir = output_dir_reduce_with_formatter,
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)

genrule(
    name = "format_golden_reduced_t_c",
    srcs = ["golden_reduced_t.c"],
    outs = ["formatted_golden_reduced_t.c"],
    cmd = "cat $(location golden_reduced_t.c) | clang-format > $@",
)

golden_test(
    name = "golden_test_reduction_with_clang_format",
    golden_file = "formatted_golden_reduced_t.c",
    test_file = "%s/t.c" % output_dir_reduce_with_formatter,
)

filegroup(
    name = "files",
    srcs = [
        "grep_based_r.sh",
        "r.sh",
        "t.c",
    ],
)
