package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "AbstractDeltaDebuggerTest",
    srcs = ["AbstractDeltaDebuggerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/delta",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "PartitionTest",
    srcs = ["PartitionTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/delta",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "PristineDeltaDebuggerTest",
    srcs = ["PristineDeltaDebuggerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/delta",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "PristineProbabilisticDeltaDebuggerTest",
    srcs = ["PristineProbabilisticDeltaDebuggerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/delta",
        "//src/org/perses/util",
    ],
)
