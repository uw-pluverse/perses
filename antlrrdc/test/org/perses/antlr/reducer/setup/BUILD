load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "SetupTest",
    srcs = [
        "SetupTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//antlrrdc/src/org/perses/antlr/reducer/setup",
        "//test/org/perses/antlr:AbstractAntlrrdcTest",
    ],
)
