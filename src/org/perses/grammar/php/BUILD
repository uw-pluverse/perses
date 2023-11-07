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
    name = "gen_PhpLexerBase",
    srcs = ["PhpLexerBase.java.txt"],
    outs = ["PhpLexerBase.java"],
    cmd = "cat <( echo 'package org.perses.grammar.php;' ) $< > $@",
)

antlr_codegen_lexer(
    name = "php_lexer",
    additional_source_files = [
        "PhpLexerBase.java",
    ],
    java_pkg_name = "org.perses.grammar.php",
    lexer_grammar_file = "PhpLexer.g4",
    lexer_java_file_name = "PhpLexer.java",
)

pnf_convert(
    name = "normalize_php_to_pnf",
    src = "PhpParser.g4",
    out = "PnfPhpParser.g4",
    lexer_grammar = "PhpLexer.g4",
    start_rule_name = "htmlDocument",
)

antlr_codegen_parser(
    name = "orig_php_parser",
    java_pkg_name = "org.perses.grammar.php",
    lexer_grammar_file = "PhpLexer.g4",
    parser_grammar_file = "PhpParser.g4",
    parser_java_file_name = "PhpParser.java",
    deps = [
        ":php_lexer",
    ],
)

antlr_codegen_parser(
    name = "pnf_php_parser",
    java_pkg_name = "org.perses.grammar.php",
    lexer_grammar_file = "PhpLexer.g4",
    parser_grammar_file = "PnfPhpParser.g4",
    parser_java_file_name = "PnfPhpParser.java",
    deps = [
        ":php_lexer",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = ["PhpParserFacade.kt"],
    deps = [
        ":language_kind",
        ":orig_php_parser",
        ":php_lexer",
        ":pnf_php_parser",
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
    srcs = ["LanguagePhp.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

filegroup(
    name = "grammar_files",
    srcs = [
        "PhpLexer.g4",
        "PhpParser.g4",
    ],
)
