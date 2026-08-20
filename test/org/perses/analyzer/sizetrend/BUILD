load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "SizeTrendDataManagerTest",
    srcs = ["SizeTrendDataManagerTest.kt"],
    test_class = "org.perses.analyzer.sizetrend.SizeTrendDataManagerTest",
    deps = [
        "//:truth",
        "//src/org/perses/analyzer/sizetrend:sizetrend_lib",
    ],
)
