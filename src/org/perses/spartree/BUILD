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
        "AbstractSparTreeEdit.kt",
        "AbstractSparTreeEditListener.kt",
        "AbstractSparTreeNode.kt",
        "AbstractTokenizedProgramCustomizer.kt",
        "AbstractTreeEditAction.kt",
        "AbstractTreeNode.kt",
        "AbstractUnmodifiableSparTree.kt",
        "AbstructNodeReplacementTreeEdit.kt",
        "AnyNodeReplacementTreeEdit.kt",
        "ChildHoistingAction.kt",
        "ChildHoistingActionSet.kt",
        "ErrorMessage.kt",
        "LexerRuleSparTreeNode.kt",
        "NodeActionSetCache.kt",
        "NodeDeletionAction.kt",
        "NodeDeletionActionSet.kt",
        "NodeDeletionTreeEdit.kt",
        "NodeReplacementTreeEdit.kt",
        "NullNodeActionSetCache.kt",
        "ParserRuleSparTreeNode.kt",
        "SparTree.kt",
        "SparTreeBuilder.kt",
        "SparTreeSimplifier.kt",
    ],
    deps = [
        ":tree_node_filter_result",
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/pnf:mutable_ast_and_util",
        "//src/org/perses/antlr",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:parse_tree_util",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/program",
        "//src/org/perses/util",
        "//src/org/perses/util:mutable_int",
        "//src/org/perses/util:simple_stack_and_queue",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
