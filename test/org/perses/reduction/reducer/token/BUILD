load(
    "//test/org/perses:test.bzl",
    "copy",
    "cross_folder_golden_test",
    "golden_test",
)
load("//src/org/perses:reduction.bzl", "reduce")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "ConcurrentTokenSlicerFunctionalTest",
    srcs = ["ConcurrentTokenSlicerFunctionalTest.kt"],
    data = [
        "//test/org/perses/benchmark_toys/delta_1:files",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:org_antlr_antlr4",
    ],
)

kt_jvm_test(
    name = "ConcurrentTokenSlicerTaskDescTest",
    srcs = ["ConcurrentTokenSlicerTaskDescTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:org_antlr_antlr4",
    ],
)

kt_jvm_test(
    name = "TokenSlicerTest",
    timeout = "long",
    srcs = ["TokenSlicerTest.kt"],
    data = [
        "//test_data/delta_1",
        "//test_data/scala_helloworld",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:org_antlr_antlr4",
    ],
)

kt_jvm_test(
    name = "DeltaDebuggingReducerTest",
    timeout = "long",
    srcs = ["DeltaDebuggingReducerTest.kt"],
    data = [
        "//test_data/delta_3",
        "//test_data/scala_helloworld",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:org_antlr_antlr4",
    ],
)
