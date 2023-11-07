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

genrule(
    name = "gen_Python3LexerBase",
    srcs = ["Python3LexerBase.java.txt"],
    outs = ["Python3LexerBase.java"],
    cmd = "cat <( echo 'package org.perses.grammar.python3;' ) $< > $@",
)

antlr_codegen_lexer(
    name = "python3_lexer",
    additional_source_files = [
        "Python3LexerBase.java",
    ],
    java_pkg_name = "org.perses.grammar.python3",
    lexer_grammar_file = "Python3Lexer.g4",
    lexer_java_file_name = "Python3Lexer.java",
)

pnf_convert(
    name = "normalize_python3_to_pnf",
    src = "Python3Parser.g4",
    out = "PnfPython3Parser.g4",
    lexer_grammar = "Python3Lexer.g4",
    start_rule_name = "file_input",
)

antlr_codegen_parser(
    name = "pnf_python3_parser",
    java_pkg_name = "org.perses.grammar.python3",
    lexer_grammar_file = "Python3Lexer.g4",
    parser_grammar_file = "PnfPython3Parser.g4",
    parser_java_file_name = "PnfPython3Parser.java",
    deps = [
        ":python3_lexer",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = ["Python3ParserFacade.kt"],
    deps = [
        ":language_kind",
        ":pnf_python3_parser",
        ":python3_lexer",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguagePython3.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
