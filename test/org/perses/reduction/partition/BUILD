package(default_visibility = ["//test/org/perses:__subpackages__"])

java_test(
    name = "SimpleLevelPartitionPolicyTest",
    srcs = ["SimpleLevelPartitionPolicyTest.java"],
    data = ["//test_data/misc"],
    test_class = "org.perses.reduction.partition.SimpleLevelPartitionPolicyTest",
    deps = [
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/tree/spar",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
    ],
)
