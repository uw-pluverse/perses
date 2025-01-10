load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_test(
    name = "DeltaDebuggerFactoryTest",
    srcs = [
        "DeltaDebuggerFactoryTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:ListInputMinimizerFactory",
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

kt_jvm_test(
    name = "PristineDeltaDebuggerTest",
    srcs = ["PristineDeltaDebuggerTest.kt"],
    deps = [
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
        "//:guava",
        "//:truth",
        "//src/org/perses/listminimizer",
        "//src/org/perses/util",
    ],
)
