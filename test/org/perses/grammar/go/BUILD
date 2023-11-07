load("//test/org/perses:test.bzl", "cross_folder_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

cross_folder_golden_test(
    name = "test_pnf_go_grammar",
    golden_file = "golden_pnf_go.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/go:normalize_go_to_pnf",
)

kt_jvm_test(
    name = "PnfGoParserFacadeTest",
    size = "enormous",  # This is a slow test.
    srcs = ["PnfGoParserFacadeTest.kt"],
    data = [],
    shard_count = 7,
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/go:parser_facade",
        "//test/org/perses:test_util",
    ],
)
