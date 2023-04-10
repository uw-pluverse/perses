package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

# This is the interim target for the ast in kotlin. After all Java files are migrated to kotlin,
# this target should be renamed to 'ast'.
kt_jvm_library(
    name = "ast",
    srcs = [
        "AbstractAstVisitor.kt",
        "AbstractLexerCommand.kt",
        "AbstractPersesAst.kt",
        "AbstractPersesEnumAst.kt",
        "AbstractPersesLexerRuleAst.kt",
        "AbstractPersesQuantifiedAst.kt",
        "AbstractPersesRuleDefAst.kt",
        "AbstractPersesRuleElement.kt",
        "AbstractPersesTerminalAst.kt",
        "AstEdit.kt",
        "AstTag.kt",
        "DefaultAstVisitor.kt",
        "EpsilonInfo.kt",
        "LexerModeWithLexerRules.kt",
        "LexerRuleList.kt",
        "PersesActionAst.kt",
        "PersesAlternativeBlockAst.kt",
        "PersesChannelDefinitionAst.kt",
        "PersesEpsilonAst.kt",
        "PersesFragmentLexerRuleAst.kt",
        "PersesGrammar.kt",
        "PersesGrammarOptionsAst.kt",
        "PersesLexerCharSet.kt",
        "PersesLexerCommandAst.kt",
        "PersesLexerRuleAst.kt",
        "PersesNamedAction.kt",
        "PersesNotAst.kt",
        "PersesOptionalAst.kt",
        "PersesParserRuleAst.kt",
        "PersesPlusAst.kt",
        "PersesRangeAst.kt",
        "PersesRuleElementLabel.kt",
        "PersesRuleElementOption.kt",
        "PersesRuleReferenceAst.kt",
        "PersesSequenceAst.kt",
        "PersesStarAst.kt",
        "PersesTerminalAst.kt",
        "PersesTokenSetAst.kt",
        "PersesTokenSpecificationAst.kt",
        "Precedence.kt",
        "RuleEpsilonComputer.kt",
        "RuleNameRegistry.kt",
        "SmartAstConstructor.kt",
        "SymbolTable.kt",
        "TransformDecision.kt",
    ],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//src/org/perses/util",
        "//src/org/perses/util/ast",
    ],
)

kt_jvm_library(
    name = "ast_builder",
    srcs = [
        "PersesAstBuilder.kt",
    ],
    deps = [
        ":ast",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "abstract_ast_editor",
    srcs = ["AbstractAstEditor.kt"],
    deps = [
        ":ast",
    ],
)
