package(default_visibility = [
    "//atn:__subpackages__",
    "//fision:__subpackages__",
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "pattern",
    srcs = [
        "EnumOperation.kt",
        "LocalExhaustivePatternReducer.kt",
        "LocalExhaustivePatternReducerAnnotation.kt",
        "NumOfDeletesToPatterns.kt",
        "TokenEditPattern.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/reduction/reducer/token:concurrent_slicing_tasks",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//src/org/perses/spartree",
    ],
)
