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
    name = "gen_JavaScriptLexerBase",
    srcs = ["JavaScriptLexerBase.java.txt"],
    outs = ["JavaScriptLexerBase.java"],
    cmd = "cat <( echo 'package org.perses.grammar.javascript;' ) $< > $@",
)

genrule(
    name = "gen_JavaScriptParserBase",
    srcs = ["JavaScriptParserBase.java.txt"],
    outs = ["JavaScriptParserBase.java"],
    cmd = "cat <( echo 'package org.perses.grammar.javascript;' ) $< " +
          "| sed 's/JavaScriptParser\\./JavaScriptLexer\\./g' > $@",
)

antlr_codegen_lexer(
    name = "javascript_lexer",
    additional_source_files = [
        "JavaScriptLexerBase.java",
    ],
    java_pkg_name = "org.perses.grammar.javascript",
    lexer_grammar_file = "JavaScriptLexer.g4",
    lexer_java_file_name = "JavaScriptLexer.java",
)

java_library(
    name = "javascript_parser_base",
    srcs = ["JavaScriptParserBase.java"],
    deps = [
        ":javascript_lexer",
        "//:antlr_runtime",
    ],
)

antlr_codegen_parser(
    name = "orig_javascript_parser",
    java_pkg_name = "org.perses.grammar.javascript",
    lexer_grammar_file = "JavaScriptLexer.g4",
    parser_grammar_file = "JavaScriptParser.g4",
    parser_java_file_name = "JavaScriptParser.java",
    deps = [
        ":javascript_lexer",
        ":javascript_parser_base",
    ],
)

pnf_convert(
    name = "normalize_javascript_to_pnf",
    src = "JavaScriptParser.g4",
    out = "PnfJavaScriptParser.g4",
    lexer_grammar = "JavaScriptLexer.g4",
    start_rule_name = "program",
)

antlr_codegen_parser(
    name = "pnf_javascript_parser",
    java_pkg_name = "org.perses.grammar.javascript",
    lexer_grammar_file = "JavaScriptLexer.g4",
    parser_grammar_file = "PnfJavaScriptParser.g4",
    parser_java_file_name = "PnfJavaScriptParser.java",
    deps = [
        ":javascript_lexer",
        ":javascript_parser_base",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = ["JavaScriptParserFacade.kt"],
    deps = [
        ":javascript_lexer",
        ":language_kind",
        ":pnf_javascript_parser",
        "//:antlr_runtime",
        "//:flogger",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageJavaScript.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
