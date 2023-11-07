package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_lexer",
)

antlr_codegen_lexer(
    name = "IdentifierOnlyLexer",
    java_pkg_name = "org.perses.antlr.atn",
    lexer_grammar_file = "IdentifierOnlyLexer.g4",
    lexer_java_file_name = "IdentifierOnlyLexer.java",
)

kt_jvm_library(
    name = "atn",
    srcs = [
        "ATNSimulator.kt",
        "LexerAtnWrapper.kt",
    ],
    deps = [
        ":AbstractRandom",
        ":IdentifierOnlyLexer",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//src/org/perses/antlr:meta_token_info_db",
        "//src/org/perses/antlr:util",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/simulator/state",
        "//src/org/perses/antlr/atn/simulator/transition",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "AbstractRandom",
    srcs = [
        "AbstractDecisionMaker.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
    ],
)

kt_jvm_library(
    name = "atn_kt_utils",
    srcs = [
        "AtnKtUtils.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/util:simple_stack_and_queue",
    ],
)
