load("//antlropt/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load("//test/org/perses:test.bzl", "golden_test")

DEFAULT_DEPS = [
    "//src/org/perses/antlr:antlr_grammar_parser",
    "//antlropt/org/perses/antlr/ast:ast",
    "//antlropt/org/perses/antlr/pnf:pnf",
    "//src/org/perses/grammar/c:c_parser_facade",
    "//src/org/perses/grammar/java:java_parser_facade",
    "//test/org/perses:test_util",
    "@maven//:com_google_flogger_flogger_system_backend",
    "@maven//:com_google_guava_guava",
    "@maven//:com_google_truth_truth",
    "@maven//:org_antlr_antlr4",
    "@maven//:org_jgrapht_jgrapht_core",
    "//test/org/perses/antlr:GrammarTestingUtility",
]

DEFAULT_TEST_DEPS = DEFAULT_DEPS + [":PnfTestGrammar"]

java_library(
    name = "PnfTestGrammar",
    srcs = [
        "PnfLeftTestGrammar.java",
        "PnfRightTestGrammar.java",
    ],
    data = ["//test_data/antlr_grammars"],
    deps = DEFAULT_DEPS,
)

java_test(
    name = "AlternativeBlockOutliningPassTest",
    srcs = ["AlternativeBlockOutliningPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.AlternativeBlockOutliningPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "AltRulesInlinePassTest",
    srcs = ["AltRulesInlinePassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.AltRulesInlinePassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "DuplicateRuleEliminationPassTest",
    srcs = ["DuplicateRuleEliminationPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.DuplicateRuleEliminationPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "OptionalIntroducerPassTest",
    srcs = ["OptionalIntroducerPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.OptionalIntroducerPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "EliminateUnreachableRulePassTest",
    srcs = ["EliminateUnreachableRulePassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.EliminateUnreachableRulePassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "PlusIntroducerLeftPassTest",
    srcs = ["PlusIntroducerLeftPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.PlusIntroducerLeftPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "PnfBuilderTest",
    srcs = ["RuleTransitionGraphTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.RuleTransitionGraphTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "RuleRefRenamingEditTest",
    srcs = ["RuleRefRenamingEditTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.RuleRefRenamingEditTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "IndirectLeftRecursionEliminationPassTest",
    srcs = ["IndirectLeftRecursionEliminationPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.IndirectLeftRecursionEliminationPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "IndirectRightRecursionEliminationPassTest",
    srcs = ["IndirectRightRecursionEliminationPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.IndirectRightRecursionEliminationPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "StarIntroducerRightPassTest",
    srcs = ["StarIntroducerRightPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.StarIntroducerRightPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "StarIntroducerLeftPassTest",
    srcs = ["StarIntroducerLeftPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.StarIntroducerLeftPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "QuantifiedAstNormalizationPassTest",
    srcs = ["QuantifiedAstNormalizationPassTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.QuantifiedAstNormalizationPassTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "MutableGrammarTest",
    srcs = ["RuleDefMapTest.java"],
    data = ["//test_data/antlr_grammars"],
    test_class = "org.perses.antlr.pnf.RuleDefMapTest",
    deps = DEFAULT_TEST_DEPS,
)

java_test(
    name = "PnfPassManagerTest",
    srcs = ["PnfPassManagerTest.java"],
    data = [
        "golden_pnf_pass_manager_log.txt",
        "//test_data/antlr_grammars",
    ],
    test_class = "org.perses.antlr.pnf.PnfPassManagerTest",
    deps = DEFAULT_TEST_DEPS,
)

java_binary(
    name = "DumpPnfPassManagerLog",
    srcs = ["DumpPnfPassManagerLog.java"],
    main_class = "org.perses.antlr.pnf.DumpPnfPassManagerLog",
    deps = DEFAULT_TEST_DEPS,
)

genrule(
    name = "dump_pnf_pass_manager_log",
    srcs = [],
    outs = ["pnf_pass_manager_log.txt"],
    cmd = "$(location :DumpPnfPassManagerLog) $(location pnf_pass_manager_log.txt)",
    tools = [":DumpPnfPassManagerLog"],
)

golden_test(
    name = "test_pnf_pass_manager_log",
    golden_file = "golden_pnf_pass_manager_log.txt",
    test_file = "pnf_pass_manager_log.txt",
)
