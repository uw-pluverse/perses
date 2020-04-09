package(default_visibility = ["//test/org/perses:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

java_library(
    name = "reducer_functional_test_base",
    srcs = ["AbstractReducerFunctionalTest.java"],
    deps = [
        "//src/org/perses:command_options",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
    ],
)

java_library(
    name = "AbstractPersesReducerTest",
    srcs = ["AbstractPersesReducerTest.java"],
    data = [
        "//benchmark/gcc-59903:gcc59903",
        "//benchmark/gcc-71626:gcc71626",
        "//test_data/child_tree_1",
        "//test_data/child_tree_2",
        "//test_data/child_tree_3",
        "//test_data/child_tree_4",
        "//test_data/delta_1",
        "//test_data/delta_2",
        "//test_data/func_call_1",
        "//test_data/func_call_2",
        "//test_data/func_name_with_paren_1",
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    deps = [
        "//src/org/perses/tree/spar",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
    ],
)

java_test(
    name = "ProfileTest",
    srcs = ["ProfileTest.java"],
    test_class = "org.perses.reduction.ProfileTest",
    deps = ["//src/org/perses/listener:profile_event_interface"],
)


java_test(
    name = "ReducerFactoryTest",
    srcs = ["ReducerFactoryTest.java"],
    test_class = "org.perses.reduction.ReducerFactoryTest",
    deps = [
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/reduction/reducer:level_based_reducers",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_test(
    name = "ReductionConfigurationTest",
    srcs = ["ReductionConfigurationTest.kt"],
    data = [
        "//test_data/delta_1",
    ],
    test_class = "org.perses.reduction.ReductionConfigurationTest",
    deps = [
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "ReductionLevelSequenceTest",
    srcs = ["ReductionLevelSequenceTest.java"],
    test_class = "org.perses.reduction.ReductionLevelSequenceTest",
    deps = [
        "//src/org/perses/reduction:reduction_level_sequence",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "ReductionDriverTest",
    srcs = ["ReductionDriverTest.java"],
    data = [
        "//test_data/delta_1",
    ],
    test_class = "org.perses.reduction.ReductionDriverTest",
    deps = [
        "//src/org/perses:command_options",
        "//src/org/perses:language_kind",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "TokenizedProgramEncoderTest",
    srcs = ["TokenizedProgramEncoderTest.java"],
    data = [
        "clang-22704.c",
        "//test_data/delta_1",
        "//test_data/java_helloworld",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.reduction.TokenizedProgramEncoderTest",
    deps = [
        "//src/org/perses:language_kind",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_execution_cache",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/tree/spar",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

java_test(
    name = "ForwardAdjacencyMapTest",
    srcs = ["ForwardAdjacencyMapTest.java"],
    test_class = "org.perses.reduction.ForwardAdjacencyMapTest",
    deps = [
        "//src/org/perses/program",
        "//src/org/perses/reduction:test_script_execution_cache",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
        "@maven//:it_unimi_dsi_fastutil",
    ],
)

kt_jvm_test(
    name = "TestScriptExecutorServiceTest",
    srcs = ["TestScriptExecutorServiceTest.kt"],
    data = [
        "//test_data/delta_1",
        "//test_data/misc",
    ],
    test_class = "org.perses.reduction.TestScriptExecutorServiceTest",
    deps = [
        "//src/org/perses:language_kind",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "ReductionFolderManagerTest",
    srcs = ["ReductionFolderManagerTest.java"],
    data = ["//test_data/delta_1"],
    test_class = "org.perses.reduction.ReductionFolderManagerTest",
    deps = [
        "//src/org/perses:language_kind",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "encoder_benchmark",
    timeout = "eternal",
    srcs = ["TokenizedProgramEncoderBenchmark.java"],
    data = [
        "clang-22704.c",
    ],
    test_class = "org.perses.reduction.TokenizedProgramEncoderBenchmark",
    deps = [
        "//src/org/perses:language_kind",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_execution_cache",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/tree/spar",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
