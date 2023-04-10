package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("//test/org/perses:test.bzl", "copy", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_library(
    name = "test_util",
    srcs = ["TestUtility.kt"],
    data = [
        "//test_data/c_programs:clang_testsuite",
        "//test_data/c_programs:gcc_testsuite",
        "//test_data/go_programs:go_testsuite",
        "//test_data/java_programs:openjdk_testsuite",
        "//test_data/rust_programs:rust_testsuite",
        "//test_data/solidity_programs",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/adhoc:adhoc_grammar_inaller_lib",
        "//src/org/perses/grammar/adhoc:command_options",
        "//src/org/perses/grammar/adhoc:language_kind",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/java:language_kind",
        "//src/org/perses/grammar/java:parser_facade",
        "//src/org/perses/grammar/php:language_kind",
        "//src/org/perses/grammar/php:parser_facade",
        "//src/org/perses/grammar/python3:language_kind",
        "//src/org/perses/grammar/python3:parser_facade",
        "//src/org/perses/grammar/scala:language_kind",
        "//src/org/perses/grammar/scala:parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/spartree",
    ],
)

exports_files([
    "copy.sh",
    "diff.sh",
])

genrule(
    name = "gen_token_counter_file",
    srcs = [
        "//test_data/delta_1:t.c",
    ],
    outs = ["token_count.txt"],
    cmd = "$(location //src/org/perses:token_counter) $(location //test_data/delta_1:t.c) | tail -n 1 > $(location token_count.txt)",
    tools = [
        "//src/org/perses:token_counter",
    ],
)

golden_test(
    name = "golden_token_counter_file",
    golden_file = "golden_token_count_for_delta1.txt",
    test_file = "token_count.txt",
)

genrule(
    name = "get_perses_cmd_usage",
    outs = ["perses_cmd_usage.txt"],
    cmd = "$(location //src/org/perses:perses) --help > \"$@\"",
    tools = [
        "//src/org/perses",
    ],
)

golden_test(
    name = "golden_perses_cmd_usage",
    golden_file = "golden_perses_cmd_usage.txt",
    test_file = "perses_cmd_usage.txt",
)

genrule(
    name = "get_perses_cmd_usage_verbosity_level",
    srcs = [],
    outs = ["perses_cmd_usage_list_verbosity_levels.txt"],
    cmd = "$(location //src/org/perses:perses) --list-verbosity-levels > \"$@\"",
    tools = [
        "//src/org/perses",
    ],
)

golden_test(
    name = "golden_perses_cmd_usage_list_verbosity_levels",
    golden_file = "golden_perses_cmd_usage_list_verbosity_levels.txt",
    test_file = "perses_cmd_usage_list_verbosity_levels.txt",
)

genrule(
    name = "get_perses_cmd_usage_print_version",
    srcs = [],
    outs = ["perses_cmd_usage_print_version.txt"],
    cmd = "$(location //src/org/perses:perses) --version > \"$@\"",
    tools = [
        "//src/org/perses",
    ],
)

sh_test(
    name = "version_string_should_be_printed",
    srcs = ["version_string_should_be_printed.sh"],
    args = ["$(location perses_cmd_usage_print_version.txt)"],
    data = ["perses_cmd_usage_print_version.txt"],
)

sh_test(
    name = "loging_level_should_be_configurable",
    srcs = ["loging_level_should_be_configurable.sh"],
    args = ["$(location //test_data/delta_1:log_with_level_below_INFO)"],
    data = ["//test_data/delta_1:log_with_level_below_INFO"],
)

kt_jvm_test(
    name = "PersesConstantsTest",
    srcs = ["PersesConstantsTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses:perses_contants",
    ],
)

kt_jvm_test(
    name = "ReadmeTest",
    srcs = ["ReadmeTest.kt"],
    associates = [
        "//src/org/perses/grammar:facade_factory",
    ],
    data = [
        "//:README.md",
    ],
    deps = [
        "//:guava",
        "//:truth",
    ],
)

PERSES_BIN = "//src/org/perses:perses_deploy.jar"

copy(
    name = "copy_perses_deploy_jar",
    src = PERSES_BIN,
    dest = "perses_deploy.jar",
)

java_import(
    name = "perses_deploy_jar",
    jars = [
        "perses_deploy.jar",
    ],
)

kt_jvm_test(
    name = "ClassNotFoundTestCase",
    srcs = ["ClassNotFoundTestCase.kt"],
    deps = [
        ":perses_deploy_jar",
        "//:truth",
    ],
)

sh_test(
    name = "informative_error_message_should_be_printed_when_file_cannot_be_parsed",
    srcs = ["informative_error_message_in_case_of_unsupported_language.sh"],
    args = [
        "$(location %s)" % PERSES_BIN,
    ],
    data = [
        PERSES_BIN,
    ],
)
