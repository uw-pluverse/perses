load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_library(
    name = "CommonReductionIOManagerData",
    srcs = ["CommonReductionIOManagerData.kt"],
    visibility = ["//test:__subpackages__"],
    deps = [
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//src/org/perses/reduction:test_script_executor_service",
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
