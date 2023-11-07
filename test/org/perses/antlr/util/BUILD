load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "UtilTest",
    srcs = ["UtilTest.kt"],
    test_class = "org.perses.antlr.util.UtilTest",
    deps = [
        "//:truth",
        "//antlropt/src/org/perses/antlr/util",
    ],
)
