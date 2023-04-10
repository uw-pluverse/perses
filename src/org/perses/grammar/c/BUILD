package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

antlr_codegen_combined(
    name = "opt_c_grammar",
    grammar_file = "OptC.g4",
    java_pkg_name = "org.perses.grammar.c",
    lexer_java_file_name = "OptCLexer.java",
    parser_java_file_name = "OptCParser.java",
)

antlr_codegen_combined(
    name = "orig_c_grammar",
    grammar_file = "OrigC.g4",
    java_pkg_name = "org.perses.grammar.c",
    lexer_java_file_name = "OrigCLexer.java",
    parser_java_file_name = "OrigCParser.java",
)

java_library(
    name = "optc_parser_facade",
    srcs = ["CParserFacade.java"],
    deps = [
        ":language_kind",
        ":opt_c_grammar",
        ":orig_c_grammar",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)

pnf_convert(
    name = "normalize_c_to_pnf",
    src = "OrigC.g4",
    out = "PnfC.g4",
    start_rule_name = "compilationUnit",
)

antlr_codegen_combined(
    name = "pnf_c_grammar",
    grammar_file = "PnfC.g4",
    java_pkg_name = "org.perses.grammar.c",
    lexer_java_file_name = "PnfCLexer.java",
    parser_java_file_name = "PnfCParser.java",
)

java_library(
    name = "parser_facade",
    srcs = ["PnfCParserFacade.java"],
    deps = [
        ":language_kind",
        ":pnf_c_grammar",
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
    srcs = ["LanguageC.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

exports_files(["OrigC.g4"])
