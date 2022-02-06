package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "delta",
    srcs = [
        "AbstractDeltaDebugger.kt",
        "Partition.kt",
        "PristineDeltaDebugger.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/reduction:property_test_result",
    ],
)
