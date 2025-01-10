load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "LocalExhaustivePatternReducerTest",
    srcs = ["LocalExhaustivePatternReducerTest.kt"],
    associates = [
        "//src/org/perses/reduction/reducer/vulcan/pattern",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//test/org/perses:test_util",
    ],
)
