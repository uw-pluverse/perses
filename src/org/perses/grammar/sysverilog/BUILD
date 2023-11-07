package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
    "antlr_codegen_lexer",
    "antlr_codegen_parser",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

pnf_convert(
    name = "normalize_sysverilog_to_pnf",
    src = "SV3_1aParser.g4",
    out = "PnfSysVerilogHDL.g4",
    lexer_grammar = "SV3_1aLexer.g4",
    start_rule_name = "source_text",
)

antlr_codegen_lexer(
    name = "sysverilog_lexer",
    java_pkg_name = "org.perses.grammar.sysverilog",
    lexer_grammar_file = "SV3_1aLexer.g4",
    lexer_java_file_name = "SV3_1aLexer.java",
)

antlr_codegen_parser(
    name = "pnf_sysverilog_grammar",
    java_pkg_name = "org.perses.grammar.sysverilog",
    lexer_grammar_file = "SV3_1aLexer.g4",
    parser_grammar_file = "PnfSysVerilogHDL.g4",
    parser_java_file_name = "PnfSysVerilogHDL.java",
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageSystemVerilog.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = ["PnfSysverilogParserFacade.kt"],
    deps = [
        ":language_kind",
        ":pnf_sysverilog_grammar",
        ":sysverilog_lexer",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)

filegroup(
    name = "orig_grammar_file",
    srcs = ["SV3_1aParser.g4"],
)
