load("//:perses.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

package(default_visibility = ["//test:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

sanity_test(
    name = "format_sensitive_sanity_test",
    source_files = ["t.c"],
    test_script = "format_sensitive_r.sh",
)

LOG_FILE = "stdout_for_reduction_golden_test.txt"

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    log_file = LOG_FILE,
    other_flags = {
        "--hide-timestamps": "true",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority-dfs",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_fake_dependency",
    cmd_deps = "binary_as_fake_dependency_compiled_by_gcc.bin",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress_with_fake_dependency.txt",
    golden_reduced_file = "golden_reduced_t.c",
    progress_dump_file = "reduction_progress_with_fake_dependency.txt",
    reduction_algorithm = "node_priority-dfs",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_c_language_parser_for_java_file",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_reduced_t.c",
    log_file = "reduction_golden_test_with_c_language_parser_for_java_file.log",
    other_flags = {
        "--lang": "c",
    },
    reduction_algorithm = "node_priority-dfs",
    source_file = "t.unknown_language",
    test_script = "r_with_language_specified.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_brace_dyck_parser_facade",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress_with_brace_dyck_parser_facade.txt",
    golden_reduced_file = "golden_reduced_t_with_brace_dyck_parser_facade.c",
    other_flags = {
        "--parser-facade-class-name": "org.perses.grammar.dyck.BraceDyckParserFacade",
    },
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_in_fully_deterministic_mode",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_golden_test_in_fully_deterministic_mode_progress.txt",
    golden_reduced_file = "golden_reduction_golden_test_in_fully_deterministic_mode_reduced.txt",
    other_flags = {
        "--lang": "c",
        "--fully-deterministic-mode": "true",
    },
    reduction_algorithm = "node_priority-dfs",
    source_file = "t.unknown_language",
    test_script = "r_with_language_specified.sh",
)

reduction_golden_test(
    name = "format_sensitive_reduction_golden_test",
    enable_query_caching = False,
    golden_progress_file = "golden_format_sensitive_reduction_progress.txt",
    golden_reduced_file = "golden_format_sensitive_reduced_t.c",
    other_flags = {
        "--code-format": "SINGLE_TOKEN_PER_LINE",
    },
    progress_dump_file = "format_sensitive_reduction_progress.txt",
    source_file = "t.c",
    test_script = "format_sensitive_r.sh",
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
    reduction_algorithm = "node_priority-dfs",
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

reduction_golden_test(
    name = "golden_reduction_test_sequential_line_slicer",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_sequential_line_slicer_progress.txt",
    golden_reduced_file = "golden_sequential_line_slicer_reduced_t.c",
    reduction_algorithm = "sequential_line_slicer",
    source_file = "t.c",
    test_script = "grep_based_r.sh",
)

sh_test(
    name = "check_fixpoint_iterations_are_printed",
    srcs = ["reduction_log_test.sh"],
    args = [
        "$(location %s)" % LOG_FILE,
    ],
    data = [LOG_FILE],
)

golden_test(
    name = "reduction_stdout_log_golden_test",
    golden_file = "golden_stdout_log.txt",
    test_file = LOG_FILE,
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
    name = "reduction_sequential_token_slicer_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_sequential_token_slicer.txt",
    golden_reduced_file = "golden_reduced_sequential_token_slicer_t.c",
    reduction_algorithm = "token_slicer",
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
        "--default-list-minimizer-for-kleene": "PRISTINE_DDMIN",
    },
    progress_dump_file = "reduction_using_pristine_ddmin_for_reducing_kleene_progress.txt",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_using_local_exhaust_minimizer_for_reducing_kleene_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_using_local_exhaust_minimizer_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_local_exhaust_minimizer_t.c",
    other_flags = {
        "--default-list-minimizer-for-kleene": "LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION",
    },
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_using_windowed_slicer_for_reducing_kleene_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_using_windowed_slicer_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_windowed_slicer_t.c",
    other_flags = {
        "--default-list-minimizer-for-kleene": "WINDOWED_SLICER",
    },
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_using_cdd_for_reducing_kleene_test",
    delta_debugger_profile = "delta_debugger_profile_for_reduction_using_cdd_for_kleene.txt",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_delta_debugger_profile = "golden_delta_debugger_profile_for_reduction_using_cdd_for_kleene.txt",
    golden_progress_file = "golden_reduction_using_cdd_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_cdd_t.c",
    other_flags = {
        "--default-list-minimizer-for-kleene": "CDD",
    },
    progress_dump_file = "reduction_using_cdd_for_reducing_kleene_progress.txt",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_using_wdd_for_reducing_kleene_test",
    delta_debugger_profile = "delta_debugger_profile_for_reduction_using_wdd_for_kleene.txt",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_delta_debugger_profile = "golden_delta_debugger_profile_for_reduction_using_wdd_for_kleene.txt",
    golden_progress_file = "golden_reduction_using_wdd_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_wdd_t.c",
    other_flags = {
        "--default-list-minimizer-for-kleene": "WDD",
    },
    progress_dump_file = "reduction_using_wdd_for_reducing_kleene_progress.txt",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_using_wprobdd_for_reducing_kleene_test",
    delta_debugger_profile = "delta_debugger_profile_for_reduction_using_wprobdd_for_kleene.txt",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_delta_debugger_profile = "golden_delta_debugger_profile_for_reduction_using_wprobdd_for_kleene.txt",
    golden_progress_file = "golden_reduction_using_wprobdd_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_wprobdd_t.c",
    other_flags = {
        "--default-list-minimizer-for-kleene": "WPROBDD",
    },
    progress_dump_file = "reduction_using_wprobdd_for_reducing_kleene_progress.txt",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_golden_test_hdd",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_hdd_progress.txt",
    golden_reduced_file = "golden_reduced_hdd_t.c",
    reduction_algorithm = "hdd",
    source_file = "t.c",
    test_script = "r.sh",
    thread_count = 1,
)

reduction_golden_test(
    name = "reduction_using_probdd_for_reducing_kleene_test",
    delta_debugger_profile = "delta_debugger_profile_for_reduction_using_probdd_for_kleene.txt",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_delta_debugger_profile = "golden_delta_debugger_profile_for_reduction_using_probdd_for_kleene.txt",
    golden_progress_file = "golden_reduction_using_probdd_for_reducing_kleene_progress.txt",
    golden_reduced_file = "golden_reduced_probdd_t.c",
    other_flags = {
        "--default-list-minimizer-for-kleene": "PROBDD",
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

reduction_golden_test(
    name = "reduction_with_designated_parser_facade_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_with_designated_parser_facade_reduced_progress.txt",
    golden_reduced_file = "golden_with_designated_parser_facade_reduced_t.c",
    other_flags = {
        "--parser-facade-class-name": "org.perses.grammar.c.CParserFacade",
    },
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
    reduction_algorithm = "node_priority-dfs",
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
