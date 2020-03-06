package(default_visibility = [
    "//visibility:public"
])

load("//antlropt/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load("//src/org/perses/grammar:antlr_util.bzl", "antlr_codegen", "antlr_merge_grammar")

pnf_convert(
    name = "normalize_go_to_pnf",
    src = "GoParser.g4",
    out = "PnfGoParser.g4",
    start_rule_name = "sourceFile",
)

antlr_codegen(
    name = "pnf_go_grammar",
    parser_grammar_file = "PnfGoParser.g4",
    parser_java_file_name = "PnfGoParser.java",
    lexer_grammar_file = "GoLexer.g4",
    lexer_java_file_name = "GoLexer.java",
    aux_java_files = ["GoParserBase.java"],
    java_pkg_name = "org.perses.grammar.go",
)

java_library(
    name = "pnfgo_parser_facade",
    srcs = ["PnfGoParserFacade.java"],
    deps = [
        ":pnf_go_grammar",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
