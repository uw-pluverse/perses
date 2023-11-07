package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

java_library(
    name = "antlr",
    visibility = ["//src/org/perses:__subpackages__"],
    exports = [
        ":antlr_hierarchy",
        ":meta_token_info_db",
        ":util",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
    ],
)

kt_jvm_library(
    name = "util",
    srcs = [
        "AntlrGrammarUtil.kt",
        "ParseTreeUtil.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "antlr_grammar_parser",
    srcs = ["AntlrGrammarParser.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "@maven//:org_antlr_antlr_runtime",  # This is the runtime v3, required for antlr tool v4. Cannot be deleted.
    ],
)

kt_jvm_library(
    name = "antlr_hierarchy",
    srcs = [
        "GrammarHierarchy.kt",
        "GrammarHierarchyBuilder.kt",
        "RuleHierarchyEntry.kt",
    ],
    deps = [
        ":antlr_grammar_info",
        ":util",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/antlr/protobuf:grammar_hierarchy_java_proto",
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
    name = "antlr_type_wrappers",
    srcs = [
        "AntlrTypeWrappers.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
    ],
)

kt_jvm_library(
    name = "meta_token_info_db",
    srcs = [
        "LexerRuleNameAndTypeMapping.kt",
        "MetaTokenInfoDB.kt",
    ],
    deps = [
        ":antlr_type_wrappers",
        ":util",
        "//:antlr_runtime",
        "//:guava",
        "@maven//:org_apache_commons_commons_text_1_9",
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
        "//:antlr_runtime",
    ],
)

kt_jvm_library(
    name = "antlr_grammar_info",
    srcs = ["AbstractAntlrGrammar.kt"],
    deps = [
        "//antlropt/src/org/perses/antlr/pnf",
    ],
)
