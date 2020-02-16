package(default_visibility = [
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

java_library(
    name = "level_based_reducers",
    srcs = [
        "AbstractLevelBasedReducer.java",
        "HDDReducer.java",
    ],
    deps = [
        ":tree_transforms",
        "//antlropt/org/perses/antlr:enum_rule_type",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/tree/spar",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "tree_transforms",
    srcs = ["TreeTransformations.kt"],
    deps = [
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/tree/spar",
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "node_based_reducer",
    srcs = [
        "AbstractPersesNodeReducer.java",
        "PersesNodeBfsReducer.java",
        "PersesNodeDfsReducer.java",
        "PersesNodePrioritizedBfsReducer.java",
        "PersesNodePrioritizedDfsReducer.java",
    ],
    deps = [
        ":delta_debugging",
        ":tree_transforms",
        "//antlropt/org/perses/antlr:enum_rule_type",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/tree/spar",
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "delta_debugging",
    srcs = [
        "AbstractDeltaDebugger.java",
        "AbstractSpecialDeltaDebugger.java",
        "BfsDeltaDebugger.java",
        "DeltaDebugger.java",
        "DfsDeltaDebugger.java",
    ],
    deps = [
        ":tree_transforms",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/tree/spar",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
