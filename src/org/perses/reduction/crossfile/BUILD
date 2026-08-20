load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "crossfile_output_manager",
    srcs = [
        "CrossFileOutputManager.kt",
        "CrossFileProgram.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction/io:output_manager_interface",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/util/hashing",
    ],
)

kt_jvm_library(
    name = "crossfile_io_manager",
    srcs = [
        "CrossFileReductionIOManager.kt",
    ],
    deps = [
        ":crossfile_output_manager",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io:reduction_folder",
        "//src/org/perses/reduction/io:reduction_inputs",
    ],
)

kt_jvm_library(
    name = "crossfile_reduction_state",
    srcs = [
        "CrossFileReductionState.kt",
    ],
    deps = [
        ":crossfile_output_manager",
        "//:flogger",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "abstract_crossfile_reducer",
    srcs = [
        "AbstractCrossFileReducer.kt",
    ],
    deps = [
        ":crossfile_io_manager",
        ":crossfile_output_manager",
        ":crossfile_reduction_state",
        "//src/org/perses/reduction:reducer_interface",
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction:test_script_executor_service",
    ],
)

kt_jvm_library(
    name = "crossfile_transformation",
    srcs = [
        "CrossFileProgramTransformation.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/program",
    ],
)

kt_jvm_library(
    name = "crossfile_transformation_reducer",
    srcs = [
        "CrossFileTransformationReducer.kt",
    ],
    deps = [
        ":abstract_crossfile_reducer",
        ":crossfile_io_manager",
        ":crossfile_output_manager",
        ":crossfile_reduction_state",
        ":crossfile_transformation",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction:test_script_executor_service",
    ],
)

kt_jvm_library(
    name = "crossfile_file_deletion_reducer",
    srcs = [
        "CrossFileFileDeletionReducer.kt",
    ],
    deps = [
        ":abstract_crossfile_reducer",
        ":crossfile_io_manager",
        ":crossfile_output_manager",
        ":crossfile_reduction_state",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction:test_script_executor_service",
    ],
)

kt_jvm_library(
    name = "crossfile_reduction_driver",
    srcs = [
        "CrossFileReductionDriver.kt",
    ],
    deps = [
        ":abstract_crossfile_reducer",
        ":crossfile_file_deletion_reducer",
        ":crossfile_io_manager",
        ":crossfile_output_manager",
        ":crossfile_reduction_state",
        ":crossfile_transformation",
        ":crossfile_transformation_reducer",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:global_context",
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction:reduction_driver",
        "//src/org/perses/reduction:reduction_driver_interface",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/util",
    ],
)
