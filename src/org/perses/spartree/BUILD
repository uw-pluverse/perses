package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

# TODO: need to split this target. It is too big. For example, tree_node, tree_edit_actions, tree_and_tree_edit

kt_jvm_library(
    name = "tree_node_filter_result",
    srcs = [
        "TreeNodeFilterResult.kt",
    ],
)

kt_jvm_library(
    name = "spartree",
    srcs = [
        "AbstractActionSet.kt",
        "AbstractNodeActionSetCache.kt",
        "AbstractNodePayload.kt",
        "AbstractNodeReplacementTreeEdit.kt",
        "AbstractSparTreeEdit.kt",
        "AbstractSparTreeEditListener.kt",
        "AbstractSparTreeNode.kt",
        "AbstractTokenizedProgramCustomizer.kt",
        "AbstractTreeEditAction.kt",
        "AbstractTreeNode.kt",
        "AbstractUnmodifiableSparTree.kt",
        "AnyNodeReplacementTreeEdit.kt",
        "ChildHoistingActionSet.kt",
        "ErrorMessage.kt",
        "LatraGeneralActionSet.kt",
        "LatraGeneralTreeEdit.kt",
        "LexerRuleSparTreeNode.kt",
        "NodeActionSetCache.kt",
        "NodeDeletionAction.kt",
        "NodeDeletionActionSet.kt",
        "NodeDeletionTreeEdit.kt",
        "NodeReplacementAction.kt",
        "NodeReplacementTreeEdit.kt",
        "NullNodeActionSetCache.kt",
        "ParserRuleSparTreeNode.kt",
        "PlaceholderSparTreeNode.kt",
        "SparTree.kt",
        "SparTreeBuilder.kt",
        "SparTreeNodeFactory.kt",
        "SparTreeSimplifier.kt",
    ],
    deps = [
        ":tree_node_filter_result",
        "//:antlr_runtime",
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf:mutable_ast_and_util",
        "//src/org/perses/antlr",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/antlr:util",
        "//src/org/perses/program",
        "//src/org/perses/util",
        "//src/org/perses/util:mutable_int",
        "//src/org/perses/util:simple_stack_and_queue",
    ],
)

kt_jvm_library(
    name = "minimal_spartree_generator",
    srcs = [
        "MinimalSparTreeGenerator.kt",
    ],
    associates = ["//src/org/perses/spartree"],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_info",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program/printer",
        "@maven//:org_apache_commons_commons_text_1_9",
    ],
)
