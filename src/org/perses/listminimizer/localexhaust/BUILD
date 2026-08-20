load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = ["//visibility:public"])

kt_jvm_library(
    name = "localexhaust",
    srcs = [
        "CachedUniformLengthDeletionPatternSets.kt",
        "ElementEditPattern.kt",
        "EnumOperation.kt",
        "LocalExhaustCursor.kt",
        "LocalExhaustWindowedMinimizer.kt",
        "UniformLengthDeletionPatternSet.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/listminimizer:list_slider",
        "//src/org/perses/util",
    ],
)
