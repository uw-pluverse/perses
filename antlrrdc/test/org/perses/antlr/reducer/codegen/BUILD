load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "ReductionScriptTemplateTest",
    srcs = ["ReductionScriptTemplateTest.kt"],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//antlrrdc/src/org/perses/antlr/reducer/codegen:templates",
        "//test/org/perses/antlr:AbstractAntlrrdcTest",
    ],
)
