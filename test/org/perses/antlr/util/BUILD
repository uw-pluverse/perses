load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

java_test(
    name = "UtilTest",
    srcs = ["UtilTest.java"],
    test_class = "org.perses.antlr.util.UtilTest",
    deps = [
        "//antlropt/org/perses/antlr/util",
        "@maven//:com_google_truth_truth",
    ],
)

kt_jvm_test(
    name = "LexerParserCombinerTest",
    srcs = ["LexerParserCombinerTest.kt"],
    test_class = "org.perses.antlr.util.LexerParserCombinerTest",
    deps = [
        "@maven//:com_google_truth_truth",
        "//antlropt/org/perses/antlr/util:lexer_parser_combiner"
    ],
)