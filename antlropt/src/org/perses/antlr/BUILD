package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "enum_rule_type",
    srcs = [
        "RuleType.kt",
    ],
    deps = [
        "//src/org/perses/util:perses_kt_exts",
        "@maven//:org_antlr_antlr4",
    ],
)
