DEFAULT_DEPS = [
    "//antlropt/org/perses/antlr/ast",
    "//src/org/perses/antlr:antlr_grammar_parser",
    "//src/org/perses/grammar/c:c_parser_facade",
    "//src/org/perses/grammar/java:java_parser_facade",
    "//test/org/perses:test_util",
    "//test/org/perses/antlr:GrammarTestingUtility",
    "@maven//:com_google_flogger_flogger_system_backend",
    "@maven//:com_google_guava_guava",
    "@maven//:com_google_truth_truth",
    "@maven//:org_antlr_antlr4",
    "@maven//:org_antlr_antlr_runtime",
]

java_test(
    name = "PersesGrammarTest",
    srcs = ["PersesGrammarTest.java"],
    data = [
        "//test_data/antlr_grammars",
    ],
    test_class = "org.perses.antlr.ast.PersesGrammarTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "PersesAstTest",
    srcs = ["PersesAstTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.ast.PersesAstTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "RuleEpsilonComputerTest",
    srcs = ["RuleEpsilonComputerTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.ast.RuleEpsilonComputerTest",
    deps = DEFAULT_DEPS,
)
