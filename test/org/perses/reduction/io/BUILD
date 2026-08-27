load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

# Driver-agnostic test scaffolding (temp dir, script, mutable files, inputs, result folder, executor)
# shared by the single-file token data below and the cross-file test data; the IO manager is the only
# per-flavor difference, left abstract.
kt_jvm_library(
    name = "AbstractReductionTestData",
    srcs = ["AbstractReductionTestData.kt"],
    visibility = [
        "//astra:__subpackages__",
        "//test:__subpackages__",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/reduction:global_execution_cache",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/io",
        "//src/org/perses/util",
        "//src/org/perses/util/hashing",
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_library(
    name = "CommonReductionIOManagerData",
    srcs = ["CommonReductionIOManagerData.kt"],
    visibility = ["//test:__subpackages__"],
    deps = [
        ":AbstractReductionTestData",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/program",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
    ],
)

kt_jvm_test(
    name = "AbstractReductionIOManagerTest",
    srcs = ["AbstractReductionIOManagerTest.kt"],
    associates = [
        "//src/org/perses/reduction/io",
    ],
    deps = [
        ":CommonReductionIOManagerData",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
    ],
)

kt_jvm_test(
    name = "ReductionIOManagerTest",
    srcs = ["ReductionIOManagerTest.kt"],
    associates = [
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
    ],
    deps = [
        ":CommonReductionIOManagerData",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "PerFileSizeMetricsTest",
    srcs = [
        "PerFileSizeMetricsTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/util",
        "//src/org/perses/util:immutable_int_array",
    ],
)

kt_jvm_test(
    name = "ReductionFolderTest",
    srcs = [
        "ReductionFolderTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/reduction/io:reduction_folder",
        "//src/org/perses/reduction/io:reduction_inputs",
    ],
)
