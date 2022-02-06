package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_lexer",
    "antlr_codegen_parser",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

antlr_codegen_lexer(
    name = "cpp_lexer",
    java_pkg_name = "org.perses.grammar.cpp",
    lexer_grammar_file = "CPP14Lexer.g4",
    lexer_java_file_name = "CPP14Lexer.java",
)

pnf_convert(
    name = "normalize_cpp_to_pnf",
    src = "CPP14Parser.g4",
    out = "PnfCPP14Parser.g4",
    lexer_grammar = "CPP14Lexer.g4",
    start_rule_name = "translationUnit",
)

antlr_codegen_parser(
    name = "cpp_parser",
    java_pkg_name = "org.perses.grammar.cpp",
    lexer_grammar_file = "CPP14Lexer.g4",
    parser_grammar_file = "PnfCPP14Parser.g4",
    parser_java_file_name = "PnfCPP14Parser.java",
    deps = [
        ":cpp_lexer",
    ],
)

java_library(
    name = "parser_facade",
    srcs = ["PnfCppParserFacade.java"],
    deps = [
        ":cpp_lexer",
        ":cpp_parser",
        ":language_kind",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageCpp.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
