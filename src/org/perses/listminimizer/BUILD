load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "list_slider",
    srcs = [
        "BackwardWindowSlider.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "interfaces",
    srcs = [
        "AbstractConfigCache.kt",
        "AbstractDefaultListMinimizer.kt",
        "AbstractListMinimizer.kt",
        "AbstractListMinimizerListener.kt",
        "AbstractProbabilisticDeltaDebugger.kt",
        "AbstractWindowedSlicer.kt",
        "CompoundListMinimizerListener.kt",
        "ElementWrapper.kt",
        "IPropertyTester.kt",
        "ListMinimizerArguments.kt",
        "ListMinimizerListenerAdaptor.kt",
        "ListMinimizerProgressListener.kt",
        "NullListMinimizerListener.kt",
        "PartitionList.kt",
    ],
    deps = [
        ":Partition",
        "//:guava",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "listminimizer",
    srcs = [
        "ConcurrentWindowedSlicer.kt",
        "CounterBasedDeltaDebugger.kt",
        "PristineDeltaDebugger.kt",
        "PristineProbabilisticDeltaDebugger.kt",
        "WeightedDeltaDebugger.kt",
        "WeightedProbabilisticDeltaDebugger.kt",
        "WindowedSlicer.kt",
    ],
    exports = [
        "//src/org/perses/listminimizer/localexhaust",
    ],
    deps = [
        ":Partition",
        ":interfaces",
        ":list_slider",
        "//:guava",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "enum_list_input_minimizer_type",
    srcs = [
        "EnumListMinimizerType.kt",
    ],
)

kt_jvm_library(
    name = "ListMinimizerFactory",
    srcs = [
        "ListMinimizerFactory.kt",
    ],
    deps = [
        ":enum_list_input_minimizer_type",
        ":interfaces",
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
    ],
)
