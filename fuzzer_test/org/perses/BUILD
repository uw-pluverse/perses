java_test(
    name = "fuzzer_test",
    srcs = ["FuzzerTest.java"],
    test_class = "org.perses.fuzzer.FuzzerTest",
    deps = [
        "//antlropt/org/perses/antlr/ast",
        "//fuzzer/org/perses:perses_fuzzer",
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
