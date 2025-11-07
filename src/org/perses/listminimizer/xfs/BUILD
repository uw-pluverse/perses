load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "xfs",
    srcs = [
        "AbstractTreeTraversalBasedListMinimizer.kt",
        "BfsListMinimizer.kt",
        "DeltaDebugger.kt",
        "DfsListMinimizer.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/listminimizer:Partition",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
    ],
)
