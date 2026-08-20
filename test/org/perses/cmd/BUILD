load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "InputFlagGroupTest",
    srcs = ["InputFlagGroupTest.kt"],
    # Associate (not just depend) so the test can use the `internal` accessors of InputFlagGroup.
    associates = [
        "//src/org/perses/cmd:reduction_flags",
    ],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "ListMinimizerMicrobenchmarkingFlagGroupTest",
    srcs = ["ListMinimizerMicrobenchmarkingFlagGroupTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/cmd:reduction_flags",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/util",
    ],
)
