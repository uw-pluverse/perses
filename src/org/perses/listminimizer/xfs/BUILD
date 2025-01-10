load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "xfs",
    srcs = [
        "AbstractSpecialDeltaDebugger.kt",
        "BfsDeltaDebugger.kt",
        "DeltaDebugger.kt",
        "DfsDeltaDebugger.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:Partition",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
        "//src/org/perses/util:Interval",
    ],
)
