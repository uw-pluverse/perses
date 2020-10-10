load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

java_test(
    name = "OptCParserTest",
    size = "large",  # This is a slow test.
    srcs = ["OptCParserTest.java"],
    shard_count = 1,
    test_class = "org.perses.grammar.c.OptCParserTest",
    deps = [
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

kt_jvm_test(
    name = "PnfCParserFacadeTest",
    size = "large",  # This is a slow test.
    srcs = ["PnfCParserFacadeTest.kt"],
    data = ["golden_pnf_c.g4"],
    shard_count = 1,
    deps = [
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

kt_jvm_test(
    name = "PreprocessedCFileParserTest",
    srcs = ["PreprocessedCFileParserTest.kt"],
    data = ["//test_data/c_programs/preprocessed_files"],
    test_class = "org.perses.grammar.c.PreprocessedCFileParserTest",
    deps = [
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
