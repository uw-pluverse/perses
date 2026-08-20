load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "token_slicer",
    srcs = [
        "AbstractStateBasedConcurrentReducer.kt",
        "AbstractTokenSlicerAnnotation.kt",
        "CanonicalConcurrentStateBasedLineSlicer.kt",
        "CanonicalLineBasedConcurrentTokenSlicer.kt",
        "CanonicalLineBasedTokenSlicer.kt",
        "ConcurrentStateBasedDeltaReducer.kt",
        "ConcurrentStateBasedLineSlicer.kt",
        "ConcurrentStateBasedTokenSlicer.kt",
        "ConcurrentTokenSlicer.kt",
        "DeltaDebuggingReducer.kt",
        "LineBasedConcurrentTokenSlicer.kt",
        "LineBasedTokenSlicer.kt",
        "TokenSlicer.kt",
    ],
    deps = [
        "//src/org/perses/grammar/line:parser_facade",
        "//src/org/perses/listminimizer",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/spartree",
    ],
)
