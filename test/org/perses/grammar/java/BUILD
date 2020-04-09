java_test(
    name = "OptJavaParserTest",
    size = "large",  # This is a slow test.
    srcs = ["OptJavaParserTest.java"],
    shard_count = 1,
    test_class = "org.perses.grammar.java.OptJavaParserTest",
    deps = [
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/java:java_parser_facade",
        "//test/org/perses:test_util",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:com_google_truth_truth",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
