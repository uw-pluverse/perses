package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

java_library(
    name = "test_script_execution_cache",
    srcs = [
        "AbstractForwardAdjacencyMap.java",
        "AbstractTestScriptExecutionCache.java",
        "AbstractTestScriptExecutionCacheProfiler.java",
        "NullTestScriptExecutionCache.java",
        "TestScriptExecutionCache.java",
        "TokenizedProgramEncoder.java",
    ],
    deps = [
        ":test_script",
        "//src/org/perses/program",
        "//src/org/perses/util:percentage",
        "@maven//:com_google_errorprone_error_prone_annotations",
        "@maven//:com_google_guava_guava",
        "@maven//:it_unimi_dsi_fastutil",
        "@maven//:me_lemire_integercompression_JavaFastPFOR",
    ],
)

kt_jvm_library(
    name = "tree_edit_with_its_program",
    srcs = ["TreeEditWithItsResult.kt"],
    deps = [
        ":test_script",
        "//src/org/perses/program",
        "//src/org/perses/tree/spar",
    ],
)

kt_jvm_library(
    name = "test_script",
    srcs = ["TestScript.kt"],
    deps = [
        "//src/org/perses/util",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_apache_commons_commons_exec",
    ],
)

java_library(
    name = "reduction_level",
    srcs = ["ReductionLevel.java"],
    deps = [
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "@maven//:com_google_guava_guava",
    ],
)


kt_jvm_library(
    name = "reduction_configuration",
    srcs = ["ReductionConfiguration.kt"],
    deps = [
        "//src/org/perses:language_kind",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/util",
        "@maven//:com_google_guava_guava",
        "@maven//:org_checkerframework_checker_qual",
    ],
)

kt_jvm_library(
    name = "actionset_profiler",
    srcs = ["AbstractActionSetProfiler.kt"],
    deps = [
        "//src/org/perses/tree/spar",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "abstract_reducer",
    srcs = [
        "AbstractReducer.kt",
        "AbstractReductionEvent.kt",
        "AbstractReductionListener.kt",
        "ReducerAnnotation.kt",
        "ReducerContext.kt",
        "ReductionListenerManager.kt",
        "ReductionState.kt",
    ],
    deps = [
        ":actionset_profiler",
        ":reduction_configuration",
        ":test_script",
        ":test_script_execution_cache",
        ":test_script_executor_service",
        ":tree_edit_with_its_program",
        "//src/org/perses/program",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "test_script_executor_service",
    srcs = [
        "ReductionFolder.kt",
        "ReductionFolderManager.kt",
        "TestScriptExecutorService.kt",
    ],
    deps = [
        ":test_script",
        ":test_script_execution_cache",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/util",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "reducer_factory",
    srcs = ["ReducerFactory.kt"],
    deps = [
        ":abstract_reducer",
        ":reduction_configuration",
        ":test_script_executor_service",
        "//src/org/perses/reduction/reducer:level_based_reducers",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "reduction_level_sequence",
    srcs = ["IReductionLevelSequence.java"],
    deps = [
        "//src/org/perses:perses_exception",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "reduction_driver",
    srcs = ["ReductionDriver.kt"],
    deps = [
        ":abstract_reducer",
        ":actionset_profiler",
        ":reducer_factory",
        ":reduction_configuration",
        ":test_script_execution_cache",
        ":test_script_executor_service",
        "//src/org/perses:command_options",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/program",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
