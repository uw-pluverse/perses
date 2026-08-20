load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//atn/src/org/perses/reduction/reducer/pattern:__subpackages__",
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_library(
    name = "level_based_reducers",
    srcs = [
        "HDDReducerAnnotations.kt",
        "LevelBasedReducer.kt",
        "PristineHDDReducer.kt",
    ],
    deps = [
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/reducer:enum_mimir_reduction_algorithm",
        "//src/org/perses/reduction/reducer:mimir_strategies",
        "//src/org/perses/spartree",
    ],
)
