package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

java_library(
    name = "antlr",
    visibility = ["//src/org/perses:__subpackages__"],
    exports = [
        ":antlr_grammar_util",
        ":antlr_hierarchy",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
    ],
)

java_library(
    name = "antlr_grammar_util",
    srcs = ["AntlrGrammarUtil.java"],
    deps = [
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

java_library(
    name = "antlr_grammar_parser",
    srcs = ["AntlrGrammarParser.java"],
    deps = [
        "//:guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr_runtime",
    ],
)

kt_jvm_library(
    name = "antlr_hierarchy",
    srcs = [
        "GrammarHierarchy.kt",
        "GrammarHierarchyBuilder.kt",
        "RuleHierarchyInfo.kt",
    ],
    deps = [
        ":antlr_grammar_info",
        ":antlr_grammar_util",
        "//:flogger",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_antlr_antlr_runtime",
    ],
)

kt_jvm_library(
    name = "antlr_compiler",
    srcs = ["AntlrCompiler.kt"],
    deps = [
        ":abstract_grammar_stub",
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//antlropt/src/org/perses/antlr/util",
        "//antlropt/src/org/perses/antlr/util:antlr_tool_wrapper",
        "//src/org/perses/program:source_file",
        "//src/org/perses/util",
        "//src/org/perses/util:file_name_content_pair",
        "//src/org/perses/util/java",
    ],
)

kt_jvm_library(
    name = "abstract_grammar_stub",
    srcs = [
        "AbstractGrammarStub.kt",
        "AbstractGrammarStubFactory.kt",
    ],
    deps = [
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/util:file_name_content_pair",
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
        "//antlropt/src/org/perses/antlr/pnf",
    ],
)

kt_jvm_library(
    name = "parse_tree_util",
    srcs = [
        "ParseTreeUtil.kt",
    ],
    deps = [
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
