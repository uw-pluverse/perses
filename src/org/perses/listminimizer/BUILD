load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "listminimizer",
    srcs = [
        "AbstractConfigCache.kt",
        "AbstractDefaultDeltaDebugger.kt",
        "AbstractListInputMinimizer.kt",
        "AbstractListInputMinimizerListener.kt",
        "AbstractProbabilisticDeltaDebugger.kt",
        "CounterBasedDeltaDebugger.kt",
        "IPropertyTester.kt",
        "ListInputMinimizerProgressListener.kt",
        "PartitionList.kt",
        "PristineDeltaDebugger.kt",
        "PristineProbabilisticDeltaDebugger.kt",
        "Slicer.kt",
        "WeightedDeltaDebugger.kt",
        "WeightedProbabilisticDeltaDebugger.kt",
    ],
    deps = [
        ":Partition",
        "//:guava",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
        "//src/org/perses/util:Interval",
    ],
)

kt_jvm_library(
    name = "enum_list_input_minimizer_type",
    srcs = [
        "EnumListInputMinimizerType.kt",
    ],
)

kt_jvm_library(
    name = "ListInputMinimizerFactory",
    srcs = [
        "ListInputMinimizerFactory.kt",
    ],
    deps = [
        ":enum_list_input_minimizer_type",
        ":listminimizer",
        "//src/org/perses/listminimizer/xfs",
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
