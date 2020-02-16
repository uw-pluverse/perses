package(default_visibility = [
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "partition",
    srcs = ["Partition.kt"],
    deps = [
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "level_partition_policy",
    srcs = [
        "AbstractLevelPartitionPolicy.java",
        "SimpleLevelPartitionPolicy.java",
    ],
    deps = [
        ":partition",
        "//src/org/perses/reduction:reduction_level",
        "@maven//:com_google_guava_guava",
    ],
)
