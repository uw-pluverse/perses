load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//atn:__subpackages__",
    "//fision:__subpackages__",
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_library(
    name = "pattern",
    srcs = [
        "LocalExhaustivePatternReducer.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/listminimizer/localexhaust",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/spartree",
    ],
)
