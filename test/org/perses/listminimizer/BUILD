load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_test(
    name = "AbstractListMinimizerListenerTest",
    srcs = [
        "AbstractListMinimizerListenerTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/listminimizer:interfaces",
    ],
)

kt_jvm_test(
    name = "ListSliderTest",
    srcs = [
        "ListSliderTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/listminimizer:list_slider",
    ],
)

kt_jvm_test(
    name = "DeltaDebuggerFactoryTest",
    srcs = [
        "DeltaDebuggerFactoryTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:ListMinimizerFactory",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/listminimizer/xfs",
    ],
)

kt_jvm_test(
    name = "AbstractDeltaDebuggerTest",
    srcs = ["AbstractDeltaDebuggerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "PartitionTest",
    srcs = ["PartitionTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "AbstractListMinimizerTest",
    srcs = ["AbstractListMinimizerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
    ],
)

kt_jvm_library(
    name = "AbstractWeightedMinimizerTest",
    srcs = ["AbstractWeightedMinimizerTest.kt"],
    deps = [
        ":AbstractListMinimizerTest",
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
    ],
)

kt_jvm_test(
    name = "ElementDeletedElsewhereTest",
    srcs = ["ElementDeletedElsewhereTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/reduction:property_test_result",
    ],
)

kt_jvm_test(
    name = "ListMinimizerArgumentsTest",
    srcs = ["ListMinimizerArgumentsTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/reduction:property_test_result",
    ],
)

kt_jvm_test(
    name = "PristineDeltaDebuggerTest",
    srcs = ["PristineDeltaDebuggerTest.kt"],
    deps = [
        ":AbstractListMinimizerTest",
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "AbstractProbabilisticDeltaDebuggerTest",
    srcs = ["AbstractProbabilisticDeltaDebuggerTest.kt"],
    deps = [
        ":AbstractListMinimizerTest",
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "WeightedDeltaDebuggerTest",
    srcs = ["WeightedDeltaDebuggerTest.kt"],
    deps = [
        ":AbstractWeightedMinimizerTest",
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "WeightedProbabilisticDeltaDebuggerTest",
    srcs = ["WeightedProbabilisticDeltaDebuggerTest.kt"],
    deps = [
        ":AbstractWeightedMinimizerTest",
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
    ],
)

kt_jvm_test(
    name = "SpeculativeGreedyDriverTest",
    srcs = ["SpeculativeGreedyDriverTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/reduction:property_test_result",
    ],
)

kt_jvm_test(
    name = "SearchSpaceTreeTest",
    srcs = ["SearchSpaceTreeTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
    ],
)

kt_jvm_test(
    name = "AdaptiveGainDrivenListMinimizerTest",
    srcs = ["AdaptiveGainDrivenListMinimizerTest.kt"],
    deps = [
        ":AbstractWeightedMinimizerTest",
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "RccConfigEncodingTest",
    srcs = ["RccConfigEncodingTest.kt"],
    associates = ["//src/org/perses/listminimizer:interfaces"],
    deps = [
        "//:truth",
    ],
)

kt_jvm_test(
    name = "ConfigCacheEquivalenceTest",
    srcs = ["ConfigCacheEquivalenceTest.kt"],
    associates = ["//src/org/perses/listminimizer:interfaces"],
    deps = [
        "//:truth",
    ],
)
