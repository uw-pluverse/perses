package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

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
        "//kitten/src/org/perses/fuzzer/languagemodel:language_model",
        "//src/org/perses/antlr:antlr_grammar_info",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program/printer",
        "@maven//:org_apache_commons_commons_text_1_9",
    ],
)

kt_jvm_library(
    name = "generator_type",
    srcs = [
        "SparTreeGeneratorType.kt",
    ],
)
