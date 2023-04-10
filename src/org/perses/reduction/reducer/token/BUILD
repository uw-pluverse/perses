package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "token_slicer",
    srcs = [
        "AbstractConcurrentTokenSlicer.kt",
        "AbstractStateBasedConcurrentReducer.kt",
        "AbstractTokenSlicerReducer.kt",
        "ConcurrentStateBasedDeltaReducer.kt",
        "ConcurrentStateBasedLineSlicer.kt",
        "ConcurrentStateBasedTokenSlicer.kt",
        "ConcurrentTokenSlicer.kt",
        "ConcurrentTokenSlicerTaskDesc.kt",
        "DeltaDebuggingReducer.kt",
        "LineBasedConcurrentTokenSlicer.kt",
        "TokenSlicer.kt",
    ],
    deps = [
        ":concurrent_slicing_tasks",
        "//src/org/perses/delta",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:tree_edit_with_its_program",
        "//src/org/perses/reduction/partition",
        "//src/org/perses/reduction/reducer:tree_transforms",
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
        "//src/org/perses/reduction/cache:program_encoding_interface",
        "//src/org/perses/spartree",
    ],
)
