package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

java_library(
    name = "antlr",
    visibility = ["//src/org/perses:__subpackages__"],
    exports = [
        ":antlr_grammar_util",
        ":antlr_hierarchy",
        "//antlropt/org/perses/antlr:enum_rule_type",
    ],
)

java_library(
    name = "antlr_grammar_util",
    srcs = ["AntlrGrammarUtil.java"],
    deps = [
        "//antlropt/org/perses/antlr:enum_rule_type",
        "//src/org/perses/program",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

java_library(
    name = "antlr_grammar_parser",
    srcs = ["AntlrGrammarParser.java"],
    deps = [
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr_runtime",
    ],
)

java_library(
    name = "antlr_hierarchy",
    srcs = [
        "GrammarHierarchy.java",
        "GrammarHierarchyBuilder.java",
        "RuleHierarchyInfo.java",
    ],
    deps = [
        ":antlr_grammar_info",
        ":antlr_grammar_util",
        "//antlropt/org/perses/antlr:enum_rule_type",
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_antlr_antlr_runtime",
    ],
)

kt_jvm_library(
    name = "parse_tree_with_parser",
    srcs = ["ParseTreeWithParser.kt"],
    deps = [
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

kt_jvm_library(
    name = "antlr_grammar_info",
    srcs = ["AbstractAntlrGrammar.kt"],
    deps = [
        "//antlropt/org/perses/antlr/pnf",
    ],
)
