package(default_visibility = [
    "//src/org/perses/reduction:__subpackages__",
    "//test/org/perses:__subpackages__",
])

java_library(
    name = "partition",
    srcs = ["Partition.java"],
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
