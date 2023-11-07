package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_lexer",
    "antlr_codegen_parser",
)
load(
    "//src/org/perses/grammar/adhoc:adhoc_grammar.bzl",
    "pnf_parser_facade_library",
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

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.cpp",
    language_kind_full_name = "org.perses.grammar.cpp.LanguageCpp",
    lexer_file_name = "CPP14Lexer.g4",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "PnfCppParserFacade",
    parser_file_name = "CPP14Parser.g4",
    start_rule_name = "translationUnit",
    token_names_of_identifiers = ["Identifier"],
    deps = [
        ":language_kind",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageCpp.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
