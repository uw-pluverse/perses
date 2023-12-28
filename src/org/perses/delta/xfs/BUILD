package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "xfs",
    srcs = [
        "AbstractSpecialDeltaDebugger.kt",
        "BfsDeltaDebugger.kt",
        "DeltaDebugger.kt",
        "DfsDeltaDebugger.kt",
    ],
    deps = [
        ":Partition",
        "//:guava",
        "//src/org/perses/delta",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_library(
    name = "Partition",
    srcs = [
        "Partition.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/util",
    ],
)
