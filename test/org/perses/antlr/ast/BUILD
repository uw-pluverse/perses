load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

DEFAULT_DEPS = [
    "//antlropt/src/org/perses/antlr/ast",
    "//antlropt/src/org/perses/antlr/ast:ast_builder",
    "//src/org/perses/antlr:antlr_grammar_parser",
    "//src/org/perses/grammar/c:optc_parser_facade",
    "//src/org/perses/grammar/java:parser_facade",
    "//test/org/perses:test_util",
    "//test/org/perses/antlr:GrammarTestingUtility",
    "//:guava",
    "//:truth",
    "//:antlr_tool",
]

kt_jvm_test(
    name = "SimplePersesGrammarParserTest",
    srcs = [
        "SimplePersesGrammarParserTest.kt",
    ],
    data = [
        "//src/org/perses/grammar/sysverilog:orig_grammar_file",
    ],
    deps = [
        # Note, do not add more test dependencies. This test is only used to test and debug Perses grammars.
        "//:truth",
        "//:kotlin_stdib",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "PersesGrammarTest",
    srcs = ["PersesGrammarTest.kt"],
    data = [
        "//src/org/perses/grammar/sysverilog:orig_grammar_file",
        "//test_data/antlr_grammars",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "PersesAstTest",
    srcs = ["PersesAstTest.kt"],
    data = ["//test_data/antlr_grammars"],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "RuleEpsilonComputerTest",
    srcs = ["RuleEpsilonComputerTest.kt"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.ast.RuleEpsilonComputerTest",
    deps = DEFAULT_DEPS,
)
