load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_library(
    name = "CommonReductionIOManagerData",
    testonly = True,
    srcs = ["CommonReductionIOManagerData.kt"],
    visibility = ["//visibility:public"],
    deps = [
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/reduction:test_script_executor_service",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io/token:regular_output_manager_factory",
        "//src/org/perses/reduction/io/token:token_reduction_io_manager",
        "//test/org/perses:test_util",
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
        "//:kotlin_stdib",
        "//:truth",
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
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/reduction/io:reduction_folder",
    ],
)
