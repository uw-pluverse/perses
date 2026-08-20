load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "generator",
    srcs = [
        "AbstractSparTreeGenerator.kt",
        "GuidedSparTreeGenerator.kt",
        "RandomSparTreeGenerator.kt",
        "RuleGenerationInfo.kt",
    ],
    associates = ["//src/org/perses/spartree"],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//kitten/src/org/perses/fuzzer/config:testing_configuration",
        "//kitten/src/org/perses/fuzzer/languagemodel:language_model",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

kt_jvm_library(
    name = "generator_type",
    srcs = [
        "SparTreeGeneratorType.kt",
    ],
)
