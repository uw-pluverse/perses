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
    name = "property_test_result",
    srcs = [
        "CandidateOutcome.kt",
        "TestScriptVerdict.kt",
    ],
    deps = [
        "//:guava",
        "//:jackson",
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
        "//src/org/perses/program",
        "//src/org/perses/util/hashing",
    ],
)

kt_jvm_library(
    name = "reduction_configuration",
    srcs = ["ReductionConfiguration.kt"],
    deps = [
        ":reducer_name_and_desc",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program/printer",
        "//src/org/perses/reduction/reducer:enum_mimir_reduction_algorithm",
        "//src/org/perses/reduction/semantics",
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
        "AbstractWholeProgramReducer.kt",
    ],
    deps = [
        ":property_test_result",
        ":reducer_name_and_desc",
        ":test_script_executor_service",
        "//antlropt/src/org/perses/antlr/util:antlr_tool_wrapper",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io:output_manager_interface",
    ],
)

kt_jvm_library(
    name = "SparTreeListMinimizerPayload",
    srcs = [
        "SparTreeListMinimizerPayload.kt",
    ],
    deps = [
        "//src/org/perses/reduction/io:output_manager_interface",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "node_container_for_list_minimizer",
    srcs = [
        "NodeContainerForListMinimizer.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "abstract_reducer",
    srcs = [
        "AbstractNonDeletionBasedReducer.kt",
        "AbstractReductionListener.kt",
        "AbstractSparTreeReducer.kt",
        "AsyncReductionListenerManager.kt",
        "FixpointReductionState.kt",
        "InputRepresentation.kt",
        "ReducerAnnotation.kt",
        "ReducerContext.kt",
        "ReducerResult.kt",
    ],
    deps = [
        ":SparTreeListMinimizerPayload",
        ":actionset_profiler",
        ":future_execution_result_triple",
        ":node_container_for_list_minimizer",
        ":reducer_context_interface",
        ":reducer_interface",
        ":reducer_name_and_desc",
        ":reduction_configuration",
        ":test_script",
        ":test_script_executor_service",
        "//:guava",
        "//src/org/perses/listminimizer",
        "//src/org/perses/listminimizer:ListMinimizerFactory",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/listminimizer/microbenchmark:list_minimization_microbenchmark",
        "//src/org/perses/listminimizer/microbenchmark:list_minimization_microbenchmark_writer",
        "//src/org/perses/program",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//src/org/perses/reduction/semantics",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
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
        "//latra/src/org/perses/reduction/reducer/latra:reducer",
        "//lpr/src/org/perses/reduction/reducer/lpr",
        "//sfc/src/org/perses/reduction/reducer/sfc:smaller_structure_replacement_reducer",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/reduction/reducer/hdd:level_based_reducers",
        "//src/org/perses/reduction/reducer/line:line_reducer",
        "//src/org/perses/reduction/reducer/token:token_slicer",
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

# The sanity-check result and exception: tiny, dependency-free value types shared by the Layer-1
# check in AbstractMain, the SanityCheckEvent it reports, and the reduction drivers. Kept in their
# own target so consumers (e.g. the event package) need not depend on the heavy driver target.
kt_jvm_library(
    name = "sanity_check",
    srcs = [
        "SanityCheckFailedException.kt",
        "SanityCheckResult.kt",
    ],
)

kt_jvm_library(
    name = "reduction_driver_interface",
    srcs = [
        "AbstractReductionDriver.kt",
        "IReductionDriver.kt",
    ],
    deps = [
        ":sanity_check",
        "//src/org/perses/mimir:semantics_provider",
        "//src/org/perses/reduction:global_context",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/io",
    ],
)

kt_jvm_library(
    name = "reduction_driver",
    srcs = [
        "AbstractProgramReductionDriver.kt",
        "EnumPipelineStage.kt",
        "LabeledPipelineStep.kt",
        "LanguageProfile.kt",
        "ListMinimizerEvaluationDriver.kt",
        "ListMinimizerEvaluationReducer.kt",
        "MainReducerOnlyOnceProgramReductionDriver.kt",
        "PerFileReductionDriver.kt",
        "QueryCacheManager.kt",
        "ReductionDriverParams.kt",
        "RegularProgramReductionDriver.kt",
    ],
    deps = [
        ":abstract_reducer",
        ":actionset_profiler",
        ":global_context",
        ":reducer_factory",
        ":reduction_configuration",
        ":reduction_driver_interface",
        ":sanity_check",
        ":stats_of_files_under_reduction",
        ":test_script_executor_service",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//lpr/src/org/perses/reduction/reducer/lpr",
        "//src/org/perses:perses_command_options",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar:tolerant_fallback_facades",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/flattokenlist:parser_facade",
        "//src/org/perses/grammar/java:language_kind",
        "//src/org/perses/listminimizer/microbenchmark:list_minimization_microbenchmark",
        "//src/org/perses/listminimizer/microbenchmark:list_minimizer_metrics_collector",
        "//src/org/perses/listminimizer/microbenchmark:recorded_program_tokenizer",
        "//src/org/perses/program",
        "//src/org/perses/reduction/cache:PassLevelCache",
        "//src/org/perses/reduction/cache:null_query_cache",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/reduction/cache:query_cache_profiler",
        "//src/org/perses/reduction/cache:sha_hash_cache",
        "//src/org/perses/reduction/crossfile:crossfile_transformation",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_output_manager_factory_interface",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//src/org/perses/reduction/reducer/trec",
        "//src/org/perses/reduction/reducer/vulcan",
        "//src/org/perses/reduction/scheduler",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/util",
        "//src/org/perses/util:timeutil",
    ],
)
