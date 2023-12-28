package(default_visibility = [
    "//fision/src:__subpackages__",
    "//latra/src/org/perses/reduction/reducer/latra:__subpackages__",
    "//ppr/src/org/perses/ppr/diff:__subpackages__",
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
    "//weighted-dd/src/org/perses/reduction/reducer:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "tree_transforms",
    srcs = ["TreeTransformations.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "node_based_reducer",
    srcs = [
        "AbstractNodeReducer.kt",
        "PersesNodeBfsReducer.kt",
        "PersesNodeDfsReducer.kt",
        "PersesNodePrioritizedBfsReducer.kt",
        "PersesNodePrioritizedDfsReducer.kt",
        "PersesNodeReducer.kt",
        "TreeSlicer.kt",
    ],
    deps = [
        ":tree_transforms",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/delta",
        "//src/org/perses/delta:DeltaDebuggerFactory",
        "//src/org/perses/delta/xfs",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/spartree",
    ],
)
