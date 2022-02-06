load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "TokenizedProgramPrinterTest",
    srcs = ["TokenizedProgramPrinterTest.kt"],
    data = [
        "//test_data/delta_1",
        "//test_data/java_helloworld",
        "//test_data/parentheses",
    ],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "AbstractOrigFormatVisitorTest",
    srcs = ["AbstractOrigFormatVisitorTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//test/org/perses:test_util",
    ],
)
