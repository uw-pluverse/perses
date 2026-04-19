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
        "LocalExhaustivePatternReducerAnnotation.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/cache:null_query_cache",
        "//src/org/perses/reduction/reducer/token:concurrent_slicing_tasks",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//src/org/perses/spartree",
    ],
)
