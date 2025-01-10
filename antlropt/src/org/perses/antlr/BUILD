load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = ["//visibility:public"])

kt_jvm_library(
    name = "enum_rule_type",
    srcs = [
        "RuleType.kt",
    ],
    deps = [
        "//:antlr_tool",
        "//src/org/perses/util",
    ],
)
