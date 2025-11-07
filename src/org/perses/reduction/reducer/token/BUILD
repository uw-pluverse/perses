load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "token_slicer",
    srcs = [
        "AbstractConcurrentTokenSlicer.kt",
        "AbstractStateBasedConcurrentReducer.kt",
        "ConcurrentStateBasedDeltaReducer.kt",
        "ConcurrentStateBasedLineSlicer.kt",
        "ConcurrentStateBasedTokenSlicer.kt",
        "ConcurrentTokenSlicer.kt",
        "ConcurrentTokenSlicerTaskDesc.kt",
        "DeltaDebuggingReducer.kt",
        "LineBasedConcurrentTokenSlicer.kt",
        "LineBasedTokenSlicer.kt",
        "TokenSlicer.kt",
    ],
    deps = [
        ":concurrent_slicing_tasks",
        "//src/org/perses/listminimizer",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "concurrent_slicing_tasks",
    srcs = [
        "AbstractSlicingTask.kt",
        "SlicingTaskConcurrentExecutor.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:future_execution_result_triple",
        "//src/org/perses/reduction:reduction_configuration",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/cache:program_encoding_interface",
        "//src/org/perses/reduction/cache:query_cache",
        "//src/org/perses/spartree",
    ],
)
