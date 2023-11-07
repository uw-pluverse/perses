load("//test/org/perses:test.bzl", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")
load(":pnf_pass_tests.bzl", "pnf_pass_golden_test", "pnf_pass_manager_golden_test")

pnf_pass_golden_test(
    name = "test_grammar_1",
    golden_file = "test_grammar_1.g4.StarRightIntroducerPass.golden",
    input_file = "test_grammar_1.g4",
    pnf_pass_name = "org.perses.antlr.pnf.StarRightIntroducerPass",
)

pnf_pass_golden_test(
    name = "test_grammar_1_ConvertAllAltToRuleReferenceOrTerminalPass",
    golden_file = "test_grammar_1.g4.ConvertAllAltToRuleReferenceOrTerminalPass.golden",
    input_file = "test_grammar_1.g4",
    pnf_pass_name = "org.perses.antlr.pnf.ConvertAllAltToRuleReferenceOrTerminalPass",
)

# We should delete this pass in the future.
#pnf_pass_golden_test(
#    name = "lexer_with_fragments_InlineFragmentPass",
#    golden_file = "lexer_with_fragments.g4.InlineFragmentPass.golden",
#    input_file = "lexer_with_fragments.g4",
#    pnf_pass_name = "org.perses.antlr.pnf.InlineFragmentPass",
#)

pnf_pass_golden_test(
    name = "test_grammar_2",
    golden_file = "test_grammar_2.g4.StarLeftIntroducerPass.golden",
    input_file = "test_grammar_2.g4",
    pnf_pass_name = "org.perses.antlr.pnf.StarLeftIntroducerPass",
)

pnf_pass_golden_test(
    name = "test_grammar_3_StarLeftIntroducerPass",
    golden_file = "test_grammar_3.g4.StarLeftIntroducerPass.golden",
    input_file = "test_grammar_3.g4",
    pnf_pass_name = "org.perses.antlr.pnf.StarLeftIntroducerPass",
)

pnf_pass_golden_test(
    name = "test_grammar_3_EliminateEpsilonPass",
    golden_file = "test_grammar_3.g4.EliminateEpsilonPass.golden",
    input_file = "test_grammar_3.g4",
    pnf_pass_name = "org.perses.antlr.pnf.EliminateEpsilonPass",
)

pnf_pass_golden_test(
    name = "test_grammar_4_IndirectLeftRecursionEliminationPass",
    golden_file = "test_grammar_4.g4.IndirectLeftRecursionEliminationPass.golden",
    input_file = "test_grammar_4.g4",
    pnf_pass_name = "org.perses.antlr.pnf.IndirectLeftRecursionEliminationPass",
)

pnf_pass_manager_golden_test(
    name = "test_grammar_5_PnfPassManager",
    golden_file = "test_grammar_5.g4.PnfPassManager.golden",
    input_file = "test_grammar_5.g4",
    start_rule_name = "start",
)

pnf_pass_golden_test(
    name = "test_grammar_6_OptionalIntroducerPass",
    golden_file = "test_grammar_6.g4.OptionalIntroducerPass.golden",
    input_file = "test_grammar_6.g4",
    pnf_pass_name = "org.perses.antlr.pnf.OptionalIntroducerPass",
)

pnf_pass_golden_test(
    name = "test_grammar_7_QuantifiedAstNormalizationPass",
    golden_file = "test_grammar_7.g4.QuantifiedAstNormalizationPass.golden",
    input_file = "test_grammar_7.g4",
    pnf_pass_name = "org.perses.antlr.pnf.QuantifiedAstNormalizationPass",
)

pnf_pass_golden_test(
    name = "test_grammar_8_QuantifiedAstNormalizationPass",
    golden_file = "test_grammar_8.g4.QuantifiedAstNormalizationPass.golden",
    input_file = "test_grammar_8.g4",
    pnf_pass_name = "org.perses.antlr.pnf.QuantifiedAstNormalizationPass",
)

pnf_pass_golden_test(
    name = "test_grammar_9_OutlineAltBlockPassTest",
    golden_file = "test_grammar_9.g4.OutlineAltBlockPass.golden",
    input_file = "test_grammar_9.g4",
    pnf_pass_name = "org.perses.antlr.pnf.OutlineAltBlockPass",
)

pnf_pass_golden_test(
    name = "test_gramamr_9_QuantifiedAstNormalizationPassTest",
    golden_file = "test_grammar_9.g4.QuantifiedAstNormalizationPass.golden",
    input_file = "test_grammar_9.g4",
    pnf_pass_name = "org.perses.antlr.pnf.QuantifiedAstNormalizationPass",
)

kt_jvm_library(
    name = "PnfPassCommandLine",
    srcs = [
        "PnfPassCommandLine.kt",
    ],
    deps = [
        "//:guava",
        "//:jcommander",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//src/org/perses/util",
        "//src/org/perses/util/cmd",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

java_binary(
    name = "pnf_pass_command_line",
    main_class = "org.perses.antlr.pnf.PnfPassCommandLine",
    runtime_deps = [
        ":PnfPassCommandLine",
    ],
)

kt_jvm_test(
    name = "GrammarPairTest",
    srcs = [
        "GrammarPairTest.kt",
    ],
    deps = [
        "//:truth",
        "//antlropt/src/org/perses/antlr/pnf:pnf_pass_interface",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "OutlineImplicitTokenDefPassTest",
    srcs = [
        "OutlineImplicitTokenDefPassTest.kt",
    ],
    associates = [
        "//antlropt/src/org/perses/antlr/pnf:pnf_passes",
    ],
    data = [
        "//src/org/perses/grammar/c:OrigC.g4",
    ],
    deps = [
        "//:truth",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "PlusIntroducerLeftPassTest",
    srcs = ["PlusIntroducerLeftPassTest.kt"],
    data = ["//test_data/antlr_grammars"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "InlineFragmentPassTest",
    srcs = ["InlineFragmentPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "ConvertAllAltToRuleReferenceOrTerminalPassTest",
    srcs = ["ConvertAllAltToRuleReferenceOrTerminalPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "RuleRefRenamingEditTest",
    srcs = ["RuleRefRenamingEditTest.kt"],
    data = ["//test_data/antlr_grammars"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "MutableRuleDefMapTest",
    srcs = ["MutableRuleDefMapTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
    ],
)

kt_jvm_test(
    name = "MutableGrammarTest",
    srcs = ["MutableGrammarTest.kt"],
    deps = [
        ":AbstractMutableGrammarTest",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "MutableAltBlockTest",
    srcs = ["MutableAltBlockTest.kt"],
    deps = [
        ":AbstractMutableGrammarTest",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "MultiAltBlockExtractionPassTest",
    srcs = ["MultiAltBlockExtractionPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "PnfUtilTest",
    srcs = ["PnfUtilTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "AltBlockExtractionPassTest",
    srcs = ["AltBlockExtractionPassTest.kt"],
    data = ["//test_data/antlr_grammars"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "AbstractAltBlockExtractionPassTest",
    srcs = ["AbstractAltBlockExtractionPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "IndirectLeftRecursionEliminationPassTest",
    srcs = ["IndirectLeftRecursionEliminationPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_library(
    name = "AbstractMutableGrammarTest",
    srcs = [
        "AbstractMutableGrammarTest.kt",
    ],
    deps = [
        "//antlropt/src/org/perses/antlr/ast",
    ],
)

kt_jvm_test(
    name = "IndirectRightRecursionEliminationPassTest",
    srcs = ["IndirectRightRecursionEliminationPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "QuantifiedAstNormalizationPassTest",
    srcs = ["QuantifiedAstNormalizationPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//antlropt/src/org/perses/antlr/pnf:pnf_grammar_checker",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "OutlineAltBlockPassTest",
    srcs = ["OutlineAltBlockPassTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf",
        "//antlropt/src/org/perses/antlr/pnf:pnf_grammar_checker",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "AstUtilTest",
    srcs = [
        "AstUtilTest.kt",
    ],
    associates = [
        "//antlropt/src/org/perses/antlr/pnf:mutable_ast_and_util",
    ],
    deps = [
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)

kt_jvm_test(
    name = "PnfPassManagerTest",
    srcs = ["PnfPassManagerTest.kt"],
    data = [
        "grammars/SystemVerilogLexer.g4",
        "grammars/SystemVerilogParser.g4",
        "//src/org/perses/grammar/php:grammar_files",
        "//src/org/perses/grammar/sysverilog:orig_grammar_file",
        "//test_data/antlr_grammars",
    ],
    deps = [
        "//:truth",
        "//antlropt/src/org/perses/antlr/pnf:pnf_pass_manager",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "//test/org/perses/antlr/pnf:PnfTestGrammar",
    ],
)

kt_jvm_test(
    name = "RemoveUnusedLabelPassTest",
    srcs = [
        "RemoveUnusedLabelPassTest.kt",
    ],
    deps = [
        "//:truth",
        "//antlropt/src/org/perses/antlr/pnf:pnf_passes",
    ],
)
