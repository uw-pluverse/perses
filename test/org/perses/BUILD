package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("//test/org/perses:test.bzl", "golden_test")

java_library(
    name = "test_util",
    srcs = ["TestUtility.java"],
    data = [
        "//test_data/c_programs:clang_testsuite",
        "//test_data/c_programs:gcc_testsuite",
        "//test_data/go_programs:go_testsuite",
        "//test_data/java_programs:openjdk_testsuite",
        "//test_data/rust_programs:rust_testsuite",
    ],
    deps = [
        ":truth",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/java:java_parser_facade",
        "//src/org/perses/grammar/scala:pnfscala_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/tree/spar",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

java_library(
    name = "truth",
    visibility = ["//visibility:public"],
    exports = [
        "@maven//:com_google_truth_truth",
        "@maven//:com_googlecode_java_diff_utils_diffutils",
    ],
)

exports_files(["diff.sh"])

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
    srcs = [],
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

sh_test(
    name = "loging_level_should_be_configurable",
    srcs = ["loging_level_should_be_configurable.sh"],
    args = ["$(location //test_data/delta_1:log_with_level_below_INFO)"],
    data = ["//test_data/delta_1:log_with_level_below_INFO"],
)
