package(default_visibility = ["//test/org/perses:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "AbstractReducerContextTest",
    srcs = ["AbstractReducerContextTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/reduction:reducer_context_interface",
        "//src/org/perses/reduction:test_script_executor_service",
        "//test/org/perses/reduction/io:CommonReductionIOManagerData",
    ],
)

kt_jvm_test(
    name = "RestrictedFutureTest",
    srcs = [
        "RestrictedFutureTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/reduction:test_script_executor_service",
    ],
)

kt_jvm_library(
    name = "reducer_functional_test_base",
    srcs = ["AbstractReducerFunctionalTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses:command_options",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
    ],
)

kt_jvm_library(
    name = "AbstractPersesReducerTest",
    srcs = ["AbstractPersesReducerTest.kt"],
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
        "//:truth",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TestScriptHistoryTest",
    srcs = [
        "TestScriptHistoryTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/reduction:TestScriptHistory",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "ProfileTest",
    srcs = ["ProfileTest.kt"],
    test_class = "org.perses.reduction.ProfileTest",
    deps = [
        "//:truth",
        "//src/org/perses/listener:profile_event_interface",
    ],
)

kt_jvm_test(
    name = "ReducerFactoryTest",
    srcs = ["ReducerFactoryTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/reduction/reducer/token:token_slicer",
    ],
)

kt_jvm_test(
    name = "ReductionConfigurationTest",
    srcs = ["ReductionConfigurationTest.kt"],
    data = [
        "//test_data/delta_1",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
    ],
)

genrule(
    name = "profile_query_cache_memory_usage",
    srcs = [
        "//src/org/perses:perses_deploy.jar",
        "//third_party/memory_measurer:object_explorer",
        "//test_data/delta_1",
    ],
    outs = ["query_cache_memory_usage.log"],
    cmd = "java -javaagent:$(location //third_party/memory_measurer:object_explorer) " +
          " --add-opens java.base/jdk.internal.ref=ALL-UNNAMED " +  # For java 11 and above. Java 8 is not supported.
          " -jar $(location //src/org/perses:perses_deploy.jar) " +
          " --test-script test_data/delta_1/r.sh " +
          " --input-file test_data/delta_1/t.c " +
          " --profile-query-cache-memory $@ " +
          " > profile_query_cache_memory_usage.stdout_stderr.txt 2>&1",
)

sh_test(
    name = "test_query_cache_memory_usage_is_not_empty",
    srcs = ["ensure_file_is_not_empty.sh"],
    args = ["$(location query_cache_memory_usage.log)"],
    data = ["query_cache_memory_usage.log"],
)

kt_jvm_test(
    name = "ReductionLevelSequenceTest",
    srcs = ["ReductionLevelSequenceTest.kt"],
    test_class = "org.perses.reduction.ReductionLevelSequenceTest",
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction:reduction_level_sequence",
    ],
)

kt_jvm_test(
    name = "RegularProgramReductionDriverTest",
    srcs = ["RegularProgramReductionDriverTest.kt"],
    associates = [
        "//src/org/perses/reduction:reduction_driver",
    ],
    data = [
        "//test_data/delta_1",
    ],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses:command_options",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/cache:enum_query_caching_control",
        "//test/org/perses:test_util",
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
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "ReductionFolderManagerTest",
    srcs = ["ReductionFolderManagerTest.kt"],
    data = ["//test_data/delta_1"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "SortedIntArrayReferenceTest",
    srcs = ["SortedIntArrayReferenceTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction:sorted_int_arrays",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "AbstractProgramReductionDriverTest",
    srcs = ["AbstractProgramReductionDriverTest.kt"],
    associates = [
        "//src/org/perses/reduction:reduction_driver",
    ],
    deps = [
        "//:guava",
        "//:truth",
    ],
)
