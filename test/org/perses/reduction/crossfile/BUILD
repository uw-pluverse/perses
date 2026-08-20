load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

# The cross-file flavor of the shared reduction test scaffolding (//test/org/perses/reduction/io:
# AbstractReductionTestData): a CrossFileReductionIOManager plus programOf/createDriver helpers.
kt_jvm_library(
    name = "crossfile_test_data",
    testonly = True,
    srcs = ["CrossFileReductionTestData.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:global_context",
        "//src/org/perses/reduction/crossfile:crossfile_io_manager",
        "//src/org/perses/reduction/crossfile:crossfile_output_manager",
        "//src/org/perses/reduction/crossfile:crossfile_reduction_driver",
        "//src/org/perses/reduction/crossfile:crossfile_transformation",
        "//test/org/perses/reduction/io:AbstractReductionTestData",
    ],
)

kt_jvm_test(
    name = "RemoveOverrideAcrossFilesFunctionalTest",
    srcs = ["RemoveOverrideAcrossFilesFunctionalTest.kt"],
    deps = [
        ":crossfile_test_data",
        "//:guava",
        "//:truth",
        "//astra/java/src/org/perses/astra/java",
        "//src/org/perses/grammar/java:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction/crossfile:crossfile_reduction_driver",
        "//test/org/perses/reduction/io:AbstractReductionTestData",
    ],
)

kt_jvm_test(
    name = "AbstractCrossFileReducerTest",
    srcs = ["AbstractCrossFileReducerTest.kt"],
    deps = [
        ":crossfile_test_data",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/crossfile:abstract_crossfile_reducer",
        "//src/org/perses/reduction/crossfile:crossfile_output_manager",
        "//src/org/perses/reduction/crossfile:crossfile_reduction_state",
        "//test/org/perses/reduction/io:AbstractReductionTestData",
    ],
)

kt_jvm_test(
    name = "CrossFileReductionDriverTest",
    srcs = ["CrossFileReductionDriverTest.kt"],
    deps = [
        ":crossfile_test_data",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction/crossfile:crossfile_reduction_driver",
        "//src/org/perses/reduction/crossfile:crossfile_transformation",
        "//test/org/perses/reduction/io:AbstractReductionTestData",
    ],
)

kt_jvm_test(
    name = "CrossFileFileDeletionReducerTest",
    srcs = ["CrossFileFileDeletionReducerTest.kt"],
    deps = [
        ":crossfile_test_data",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction/crossfile:crossfile_file_deletion_reducer",
        "//src/org/perses/reduction/crossfile:crossfile_output_manager",
        "//src/org/perses/reduction/crossfile:crossfile_reduction_state",
        "//src/org/perses/reduction/crossfile:crossfile_transformation",
        "//test/org/perses/reduction/io:AbstractReductionTestData",
    ],
)

kt_jvm_test(
    name = "CrossFileTransformationReducerTest",
    srcs = ["CrossFileTransformationReducerTest.kt"],
    deps = [
        ":crossfile_test_data",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/crossfile:crossfile_output_manager",
        "//src/org/perses/reduction/crossfile:crossfile_reduction_state",
        "//src/org/perses/reduction/crossfile:crossfile_transformation",
        "//src/org/perses/reduction/crossfile:crossfile_transformation_reducer",
        "//test/org/perses/reduction/io:AbstractReductionTestData",
    ],
)

kt_jvm_test(
    name = "CrossFileReductionStateTest",
    srcs = ["CrossFileReductionStateTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction/crossfile:crossfile_output_manager",
        "//src/org/perses/reduction/crossfile:crossfile_reduction_state",
    ],
)

kt_jvm_test(
    name = "CrossFileReductionIOManagerTest",
    srcs = ["CrossFileReductionIOManagerTest.kt"],
    deps = [
        ":crossfile_test_data",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction/crossfile:crossfile_output_manager",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io:output_manager_interface",
        "//src/org/perses/util:file_name_content_pair",
        "//test/org/perses/reduction/io:AbstractReductionTestData",
    ],
)
