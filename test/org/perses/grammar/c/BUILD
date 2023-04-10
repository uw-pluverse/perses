load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//test/org/perses:test.bzl", "cross_folder_golden_test")

java_test(
    name = "OptCParserTest",
    size = "large",  # This is a slow test.
    srcs = ["OptCParserTest.java"],
    shard_count = 1,
    test_class = "org.perses.grammar.c.OptCParserTest",
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/c:optc_parser_facade",
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
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/c:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)

kt_jvm_test(
    name = "PreprocessedCFileParserTest",
    srcs = ["PreprocessedCFileParserTest.kt"],
    data = ["//test_data/c_programs/preprocessed_files"],
    test_class = "org.perses.grammar.c.PreprocessedCFileParserTest",
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/c:parser_facade",
        "//test/org/perses:test_util",
    ],
)
