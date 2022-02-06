package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "associativity_parser_rule_eliminator_pass",
    srcs = [
        "AssociativityParserRuleEliminatorPass.kt",
    ],
    deps = [
        ":pnf_pass_interface",
    ],
)

kt_jvm_library(
    name = "pnf_normalizer",
    srcs = ["PnfNormalizer.kt"],
    deps = [
        ":pnf",
        "//antlropt/src/org/perses/antlr/util",
        "//src/org/perses/util",
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_library(
    name = "pnf_grammar_checker",
    srcs = [
        "PnfCheckPass.kt",
        "PnfGrammarChecker.kt",
    ],
    deps = [
        ":pnf_pass_interface",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/util:antlr_tool_wrapper",
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_library(
    name = "mutable_ast_and_util",
    srcs = [
        "AstUtil.kt",
        "MutableAltBlock.kt",
        "MutableGrammar.kt",
        "OptionalExtractionUtil.kt",
    ],
    deps = [
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_library(
    name = "pnf_pass_interface",
    srcs = [
        "AbstractPnfPass.kt",
        "PnfUtil.kt",
        "ProjectedHashMultimap.kt",
        "ReplaceEdit.kt",
        "RuleRefCounterAstVisitor.kt",
        "UsedRuleNameCollector.kt",
    ],
    exports = [
        ":mutable_ast_and_util",
    ],
    deps = [
        ":mutable_ast_and_util",
        "//:flogger",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_library(
    name = "pnf_pass_manager",
    srcs = [
        "PnfPassManager.kt",
    ],
    deps = [
        ":associativity_parser_rule_eliminator_pass",
        ":pnf_grammar_checker",
        ":pnf_pass_interface",
        ":pnf_passes",
        "//:flogger",
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/util:antlr_tool_wrapper",
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_library(
    name = "pnf_passes",
    srcs = [
        "AbstractAltBlockExtractionPass.kt",
        "AbstractIndirectRecursionEliminationPass.kt",
        "AbstractStarIntroducerPass.kt",
        "AltBlockExtractionPass.kt",
        "ConvertAllAltToRuleReferenceOrTerminalPass.kt",
        "DuplicateRuleEliminationPass.kt",
        "EliminateEpsilonPass.kt",
        "EliminateUnreachableRulePass.kt",
        "IndirectLeftRecursionEliminationPass.kt",
        "IndirectRightRecursionEliminationPass.kt",
        "InlineEpsilonRuleEdit.kt",
        "InlineFragmentPass.kt",
        "InlineSingleUseAltRulePass.kt",
        "MultiAltBlockExtractionPass.kt",
        "OptionalIntroducerPass.kt",
        "OutlineAltBlockPass.kt",
        "PlusIntroducerLeftPass.kt",
        "QuantifiedAstNormalizationPass.kt",
        "RuleEditTriple.kt",
        "RuleRefRenamingEdit.kt",
        "RuleTransitionGraph.kt",
        "StarLeftIntroducerPass.kt",
        "StarRightIntroducerPass.kt",
    ],
    deps = [
        ":pnf_pass_interface",
        "//:flogger",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//src/org/perses/util:simple_stack_and_queue",
        "@maven//:org_jgrapht_jgrapht_core",
    ],
)

java_library(
    name = "pnf",
    exports = [
        ":associativity_parser_rule_eliminator_pass",
        ":pnf_pass_interface",
        ":pnf_pass_manager",
        ":pnf_passes",
    ],
)

java_binary(
    name = "pnf_main",
    srcs = ["Main.java"],
    jvm_flags = ["-ea"],
    main_class = "org.perses.antlr.pnf.Main",
    deps = [
        ":pnf",
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//antlropt/src/org/perses/antlr/util",
        "//src/org/perses/util",
        "//src/org/perses/util:file_name_content_pair",
        "@maven//:com_beust_jcommander",
    ],
)
