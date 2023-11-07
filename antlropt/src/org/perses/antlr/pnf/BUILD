package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

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
        "GrammarPair.kt",
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
        "//src/org/perses/util:file_name_content_pair",
    ],
)

kt_jvm_library(
    name = "implicit_token_def_outliner_lib",
    srcs = [
        "OutlineImplicitTokenDefMain.kt",
    ],
    deps = [
        ":pnf_pass_manager",
        ":pnf_passes",
        "//src/org/perses/util/cmd",
    ],
)

java_binary(
    name = "outline_implicit_token_def_bin",
    main_class = "org.perses.antlr.pnf.OutlineImplicitTokenDefMain",
    runtime_deps = [
        ":implicit_token_def_outliner_lib",
    ],
)

kt_jvm_library(
    name = "pnf_pass_manager",
    srcs = [
        "Main.kt",
        "PnfPassManager.kt",
    ],
    deps = [
        ":pnf_grammar_checker",
        ":pnf_pass_interface",
        ":pnf_passes",
        "//:flogger",
        "//:guava",
        "//:jcommander",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/util",
        "//antlropt/src/org/perses/antlr/util:antlr_tool_wrapper",
        "//src/org/perses/util:file_name_content_pair",
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_library(
    name = "pnf_passes",
    srcs = [
        "AbstractAltBlockExtractionPass.kt",
        "AbstractIndirectRecursionEliminationPass.kt",
        "AbstractStarIntroducerPass.kt",
        "AltBlockExtractionPass.kt",
        "AssociativityParserRuleEliminatorPass.kt",
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
        "OutlineImplicitTokenDefPass.kt",
        "PlusIntroducerLeftPass.kt",
        "QuantifiedAstNormalizationPass.kt",
        "RemoveUnusedLabelPass.kt",
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
        "//:jgrapht",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//src/org/perses/util:simple_stack_and_queue",
    ],
)

java_library(
    name = "pnf",
    exports = [
        ":pnf_pass_interface",
        ":pnf_pass_manager",
        ":pnf_passes",
    ],
)

java_binary(
    name = "pnf_main",
    jvm_flags = ["-ea"],
    main_class = "org.perses.antlr.pnf.Main",
    runtime_deps = [
        ":pnf",
        "//:guava",
        "//:jcommander",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//antlropt/src/org/perses/antlr/util",
        "//src/org/perses/util",
        "//src/org/perses/util:file_name_content_pair",
    ],
)
