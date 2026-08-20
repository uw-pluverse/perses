load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

# TODO(cnsun): need to split this target. It is too big. For example, tree_node, tree_edit_actions, tree_and_tree_edit

kt_jvm_library(
    name = "tree_node_filter_result",
    srcs = [
        "TreeNodeFilterResult.kt",
    ],
)

kt_jvm_library(
    name = "ContextDescription",
    srcs = [
        "ContextDescription.kt",
    ],
    deps = [
        "//:guava",
    ],
)

kt_jvm_library(
    name = "tree_node",
    srcs = [
        "AbstractTreeNode.kt",
        "DeepCopyResult.kt",
        "ErrorMessage.kt",
    ],
    deps = [
        ":tree_node_filter_result",
        "//:guava",
        "//src/org/perses/util",
        "//src/org/perses/util:simple_stack_and_queue",
    ],
)

kt_jvm_library(
    name = "spartree",
    srcs = [
        "AbstractActionSet.kt",
        "AbstractInternalSparTreeNode.kt",
        "AbstractNodeActionSetCache.kt",
        "AbstractNodePayload.kt",
        "AbstractNodeReplacementTreeEdit.kt",
        "AbstractSparTreeEdit.kt",
        "AbstractSparTreeEditListener.kt",
        "AbstractSparTreeNode.kt",
        "AbstractTokenizedProgramCustomizer.kt",
        "AbstractTreeEditAction.kt",
        "AbstractUnmodifiableSparTree.kt",
        "AnyNodeReplacementTreeEdit.kt",
        "DescendantHoistingTreeEdit.kt",
        "EmptySparTreeEdit.kt",
        "GroupingSparTreeNode.kt",
        "ISparTreeAntlrTreeMapping.kt",
        "LatraGeneralActionSet.kt",
        "LatraGeneralTreeEdit.kt",
        "LexerRuleSparTreeNode.kt",
        "NodeActionSetCache.kt",
        "NodeActionSetCacheResult.kt",
        "NodeDeletionAction.kt",
        "NodeDeletionActionSet.kt",
        "NodeDeletionTreeEdit.kt",
        "NodeReplacementAction.kt",
        "NodeReplacementActionSet.kt",
        "NullNodeActionSetCache.kt",
        "ParserRuleSparTreeNode.kt",
        "PlaceholderSparTreeNode.kt",
        "SparTree.kt",
        "SparTreeBuilder.kt",
        "SparTreeNodeFactory.kt",
        "SparTreeSentinelRootNode.kt",
        "SparTreeSimplifier.kt",
    ],
    deps = [
        ":ContextDescription",
        ":tree_node",
        ":tree_node_filter_result",
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/antlr",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/program",
        "//src/org/perses/util",
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
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

kt_jvm_library(
    name = "spar_tree_parser_utility",
    srcs = [
        "SparTreeParserUtility.kt",
    ],
    deps = [
        ":spartree",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)
