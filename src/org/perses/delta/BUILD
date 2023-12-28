package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "delta",
    srcs = [
        "AbstractConfigCache.kt",
        "AbstractDefaultDeltaDebugger.kt",
        "AbstractDeltaDebugger.kt",
        "AbstractDeltaDebuggerListener.kt",
        "DeltaDebuggerProgressListener.kt",
        "IPropertyTester.kt",
        "PartitionList.kt",
        "PristineDeltaDebugger.kt",
        "PristineProbabilisticDeltaDebugger.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_library(
    name = "EnumDeltaDebuggerType",
    srcs = [
        "EnumDeltaDebuggerType.kt",
    ],
)

kt_jvm_library(
    name = "DeltaDebuggerFactory",
    srcs = [
        "DeltaDebuggerFactory.kt",
    ],
    deps = [
        ":EnumDeltaDebuggerType",
        ":delta",
        "//src/org/perses/delta/xfs",
    ],
)
