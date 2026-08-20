load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//fision/src:__subpackages__",
    "//latra/src/org/perses/reduction/reducer/latra:__subpackages__",
    "//ppr/src/org/perses/ppr/diff:__subpackages__",
    "//src/org/perses/cmd:__subpackages__",
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
    "//weighted-dd/src/org/perses/reduction/reducer:__subpackages__",
])

kt_jvm_library(
    name = "enum_mimir_reduction_algorithm",
    srcs = ["EnumMimirReductionAlgorithm.kt"],
)

kt_jvm_library(
    name = "tree_transforms",
    srcs = ["TreeTransformations.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "mimir_strategies",
    srcs = [
        "AbstractLayerBasedMimirStrategy.kt",
        "AbstractMimirStrategy.kt",
        "MimirStrategyBottomLayerThenTopDown.kt",
        "MimirStrategyDagAsList.kt",
        "MimirStrategyDfsDag.kt",
        "MimirStrategyFactory.kt",
        "MimirStrategyFineDagAsList.kt",
        "MimirStrategyFinerDagAsList.kt",
        "MimirStrategyLayerByLayer.kt",
    ],
    deps = [
        ":enum_mimir_reduction_algorithm",
        "//:guava",
        "//src/org/perses/listminimizer",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "node_based_reducer",
    srcs = [
        "AbstractNodeReducer.kt",
        "CReduceReducer.kt",
        "FormatReducer.kt",
        "MimirNodeReducer.kt",
        "NonSyntacticSingleTreeNodeReducer.kt",
        "PersesNodeReducer.kt",
        "PersesNodeReducerAnnotations.kt",
        "SparTreeRootReplacementReducer.kt",
    ],
    deps = [
        ":enum_mimir_reduction_algorithm",
        ":mimir_strategies",
        ":tree_transforms",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//src/org/perses/grammar/dyck:AbstractDyckParserFacade",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/grammar/onetoken:parser_facade",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:ListMinimizerFactory",
        "//src/org/perses/listminimizer/xfs",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/reduction/io",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/util",
        "//src/org/perses/util/shell",
    ],
)
