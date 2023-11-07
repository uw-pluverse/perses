package(default_visibility = ["//test/org/perses:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "SimpleLevelPartitionPolicyTest",
    srcs = ["SimpleLevelPartitionPolicyTest.kt"],
    data = ["//test_data/misc"],
    test_class = "org.perses.reduction.partition.SimpleLevelPartitionPolicyTest",
    deps = [
        "//:truth",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)
