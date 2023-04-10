package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "action_node_collector",
    srcs = [
        "ActionNodeCollector.kt",
    ],
    deps = [
        "//antlropt/src/org/perses/antlr/ast",
    ],
)

kt_jvm_library(
    name = "passes",
    srcs = [
        "AbstractAntlrReducer.kt",
        "AbstractParserRuleAttributeReducer.kt",
        "AbstractRuleElementReducer.kt",
        "ActionsReducer.kt",
        "ArgumentsReducer.kt",
        "LocalsReducer.kt",
        "ReturnsReducer.kt",
        "RuleElementLabelCollector.kt",
        "RuleElementLabelReducer.kt",
    ],
    deps = [
        ":action_node_collector",
        "//:flogger",
        "//antlropt/src/org/perses/antlr/ast:abstract_ast_editor",
        "//antlrrdc/src/org/perses/antlr/reducer/io",
        "//src/org/perses/reduction:ListenableReductionState",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/io:output_manager_interface",
    ],
)
