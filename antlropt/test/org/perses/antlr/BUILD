load("//test/org/perses:test.bzl", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "RuleTypeTest",
    srcs = ["RuleTypeTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "@maven//:org_antlr_antlr4",
    ],
)
