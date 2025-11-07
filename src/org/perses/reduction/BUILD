load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "sorted_int_arrays",
    srcs = ["SortedIntArrayReference.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "future_execution_result_triple",
    srcs = [
        "EditTestPayload.kt",
    ],
    deps = [
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction/cache:query_cache_interface",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "ListenableReductionState",
    srcs = [
        "ListenableReductionState.kt",
    ],
    deps = [
        "//:flogger",
    ],
)

kt_jvm_library(
    name = "tree_edit_with_its_program",
    srcs = ["TreeEditWithItsResult.kt"],
    deps = [
        ":property_test_result",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "property_test_result",
    srcs = ["PropertyTestResult.kt"],
    deps = [
        "//src/org/perses/util/shell:ExitCode",
    ],
)

kt_jvm_library(
    name = "test_script",
    srcs = ["TestScript.kt"],
    deps = [
        ":property_test_result",
        "//:flogger",
        "//src/org/perses/program:source_file",
        "//src/org/perses/util",
        "//src/org/perses/util:timeutil",
        "//src/org/perses/util/shell",
        "@maven//:org_apache_commons_commons_exec",
    ],
)

kt_jvm_library(
    name = "reduction_level",
    srcs = ["ReductionLevel.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "stats_of_files_under_reduction",
    srcs = [
        "StatsOfFilesBeingReduced.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/util/hashing",
    ],
)

kt_jvm_library(
    name = "reduction_configuration",
    srcs = ["ReductionConfiguration.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program/printer",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "actionset_profiler",
    srcs = ["AbstractActionSetProfiler.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "reducer_name_and_desc",
    srcs = ["AbstractReducerNameAndDesc.kt"],
    deps = [
        "//:guava",
    ],
)

kt_jvm_library(
    name = "reducer_context_interface",
    srcs = [
        "AbstractReducerContext.kt",
    ],
    deps = [
        ":test_script_executor_service",
        "//src/org/perses/reduction/io",
    ],
)

kt_jvm_library(
    name = "reducer_interface",
    srcs = [
        "AbstractReducer.kt",
    ],
    deps = [
        ":reducer_name_and_desc",
        ":test_script_executor_service",
        "//src/org/perses/reduction/io",
    ],
)

kt_jvm_library(
    name = "SparTreeListMinimizerPayload",
    srcs = [
        "SparTreeListMinimizerPayload.kt",
    ],
    deps = [
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "abstract_reducer",
    srcs = [
        "AbstractNonDeletionBasedReducer.kt",
        "AbstractReductionListener.kt",
        "AbstractTokenReducer.kt",
        "AsyncReductionListenerManager.kt",
        "FixpointReductionState.kt",
        "ReducerAnnotation.kt",
        "ReducerContext.kt",
        "SparTreeWithParsability.kt",
    ],
    deps = [
        ":SparTreeListMinimizerPayload",
        ":actionset_profiler",
        ":future_execution_result_triple",
        ":reducer_context_interface",
        ":reducer_interface",
        ":reducer_name_and_desc",
        ":reduction_configuration",
        ":test_script",
        ":test_script_executor_service",
        ":tree_edit_with_its_program",
        "//:guava",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:ListMinimizerFactory",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/program",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "global_context",
    srcs = [
        "GlobalContext.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/reduction:global_execution_cache",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "test_script_executor_service",
    srcs = [
        "RestrictedFuture.kt",
        "TestScriptExecResult.kt",
        "TestScriptExecutorService.kt",
    ],
    deps = [
        ":global_execution_cache",
        ":test_script",
        "//:guava",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/program",
        "//src/org/perses/util",
        "//src/org/perses/util:timeutil",
    ],
)

kt_jvm_library(
    name = "reducer_factory",
    srcs = ["ReducerFactory.kt"],
    deps = [
        ":abstract_reducer",
        ":reduction_configuration",
        ":test_script_executor_service",
        "//:guava",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/latra:reducer",
        "//src/org/perses/reduction/reducer/lpr",
        "//src/org/perses/reduction/reducer/trec",
        "//src/org/perses/reduction/reducer/vulcan",
    ],
)

kt_jvm_library(
    name = "reduction_level_sequence",
    srcs = ["IReductionLevelSequence.kt"],
    deps = [
        "//:guava",
    ],
)

kt_jvm_library(
    name = "TestScriptHistory",
    srcs = [
        "TestScriptHistory.kt",
    ],
    deps = [
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/util",
        "//src/org/perses/util/shell:ExitCode",
        "@maven//:org_apache_commons_commons_csv",
    ],
)

kt_jvm_library(
    name = "global_execution_cache",
    srcs = [
        "AbstractGlobalExecutionCache.kt",
    ],
    deps = [
        "//src/org/perses/reduction:TestScriptHistory",
        "//src/org/perses/reduction/io:output_manager_interface",
    ],
)

kt_jvm_library(
    name = "reduction_driver_interface",
    srcs = [
        "AbstractReductionDriver.kt",
        "IReductionDriver.kt",
        "SanityCheckFailedException.kt",
    ],
    deps = [
        "//src/org/perses/reduction:global_context",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/io",
    ],
)

kt_jvm_library(
    name = "reduction_driver",
    srcs = [
        "AbstractProgramReductionDriver.kt",
        "RegularProgramReductionDriver.kt",
    ],
    deps = [
        ":abstract_reducer",
        ":actionset_profiler",
        ":global_context",
        ":reducer_factory",
        ":reduction_configuration",
        ":reduction_driver_interface",
        ":stats_of_files_under_reduction",
        ":test_script_executor_service",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//src/org/perses:command_options",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction/cache:PassLevelCache",
        "//src/org/perses/reduction/cache:enum_query_caching_control",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/reduction/cache:query_cache_factory",
        "//src/org/perses/reduction/cache:query_cache_profiler",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_output_manager_factory_interface",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//src/org/perses/reduction/reducer/lpr",
        "//src/org/perses/reduction/reducer/trec",
        "//src/org/perses/reduction/reducer/vulcan",
        "//src/org/perses/reduction/scheduler",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//src/org/perses/util:timeutil",
    ],
)
