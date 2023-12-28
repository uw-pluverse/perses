package(default_visibility = [
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "partition",
    srcs = [
        "AbstractLevelPartitionPolicy.kt",
        "SimpleLevelPartitionPolicy.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/delta/xfs:Partition",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)
