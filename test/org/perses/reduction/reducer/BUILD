load("//test/org/perses:test.bzl", "golden_test")
load("//src/org/perses:reduction.bzl", "reduce")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

java_test(
    name = "PersesNodeReducerFunctionalTest",
    srcs = ["PersesNodeReducerFunctionalTest.java"],
    test_class = "org.perses.reduction.reducer.PersesNodeReducerFunctionalTest",
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:level_based_reducers",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

java_test(
    name = "PersesNodeReducerJavaFunctionalTest",
    srcs = ["PersesNodeReducerJavaFunctionalTest.java"],
    data = ["//test_data/java_helloworld"],
    test_class = "org.perses.reduction.reducer.PersesNodeReducerJavaFunctionalTest",
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:level_based_reducers",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

kt_jvm_test(
    name = "HddReducerFunctionalTest",
    size = "medium",
    timeout = "moderate",
    srcs = ["HddReducerFunctionalTest.kt"],
    data = ["//test_data/java_helloworld"],
    test_class = "org.perses.reduction.reducer.HddReducerFunctionalTest",
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:level_based_reducers",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

kt_jvm_test(
    name = "TokenSlicerTest",
    srcs = ["TokenSlicerTest.kt"],
    data = ["//test_data/delta_1"],
    test_class = "org.perses.reduction.reducer.TokenSlicerTest",
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:level_based_reducers",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer:token_slicer",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

java_test(
    name = "PersesNodeReducerTest",
    srcs = ["PersesNodeReducerTest.java"],
    test_class = "org.perses.reduction.reducer.PersesNodeReducerTest",
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_level",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/partition:level_partition_policy",
        "//src/org/perses/reduction/reducer:level_based_reducers",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "//test/org/perses/reduction:AbstractPersesReducerTest",
        "//test/org/perses/reduction:reducer_functional_test_base",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

genrule(
    name = "genlog_for_delta_1_with_caching",
    srcs = [
        "//test_data/delta_1:progress_dump_t_with_cache.c",
    ],
    outs = ["reduction_log_of_delta_1_with_caching.txt"],
    cmd = "cp $(location //test_data/delta_1:progress_dump_t_with_cache.c) $(location reduction_log_of_delta_1_with_caching.txt)",
)

genrule(
    name = "genlog_for_delta_1_without_caching",
    srcs = [
        "//test_data/delta_1:progress_dump_t_wo_cache.c",
    ],
    outs = ["reduction_log_of_delta_1_wo_cache.txt"],
    cmd = "cp $(location //test_data/delta_1:progress_dump_t_wo_cache.c) $(location reduction_log_of_delta_1_wo_cache.txt)",
)

golden_test(
    name = "golden_test_reduction_process__delta_1_with_cache",
    golden_file = "golden_reduction_log_of_delta_1_with_cache.txt",
    test_file = "reduction_log_of_delta_1_with_caching.txt",
)

golden_test(
    name = "golden_test_reduction_process__delta_1_without_cache",
    golden_file = "golden_reduction_log_of_delta_1_without_cache.txt",
    test_file = "reduction_log_of_delta_1_wo_cache.txt",
)
