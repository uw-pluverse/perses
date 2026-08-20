load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//test:test.bzl", "cross_folder_golden_test")

kt_jvm_test(
    name = "DroppedCharacterCollectorTest",
    srcs = ["DroppedCharacterCollectorTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:parser_facade",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "PreprocessingDirectiveTokenTest",
    srcs = ["PreprocessingDirectiveTokenTest.kt"],
    deps = [
        "//:antlr_runtime",
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:parser_facade",
    ],
)

kt_jvm_test(
    name = "LineSpliceReconstructionTest",
    srcs = ["LineSpliceReconstructionTest.kt"],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
    ],
)

kt_jvm_test(
    name = "OptCParserTest",
    size = "large",  # This is a slow test.
    srcs = ["OptCParserTest.kt"],
    shard_count = 1,
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:parser_facade",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "LanguageCTest",
    srcs = [
        "LanguageCTest.kt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
    ],
)

cross_folder_golden_test(
    name = "golden_test_pnf_c",
    golden_file = "golden_pnf_c.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/c:PnfC.g4",
)

cross_folder_golden_test(
    name = "golden_implicit_token_outlining_c",
    golden_file = "golden_implicit_token_outlining_c.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/c:implicit_token_outlined",
)

kt_jvm_test(
    name = "PnfCParserFacadeTest",
    size = "large",  # This is a slow test.
    srcs = ["PnfCParserFacadeTest.kt"],
    data = [
        "//test_data/delta_1",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)

kt_jvm_test(
    name = "IdentifierTokenAutoDetectionTest",
    srcs = ["IdentifierTokenAutoDetectionTest.kt"],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_type_wrappers",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:optc_parser_facade",
    ],
)

kt_jvm_test(
    name = "PreprocessedCFileParserTest",
    srcs = ["PreprocessedCFileParserTest.kt"],
    data = ["//test_data/c_programs/preprocessed_files"],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:parser_facade",
    ],
)
