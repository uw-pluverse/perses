package(default_visibility = [
    "//src/org/perses/grammar:__pkg__",
    "//test/org/perses:__subpackages__",
])

load("//antlropt/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
)

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
    name = "c_parser_facade",
    srcs = ["CParserFacade.java"],
    deps = [
        ":opt_c_grammar",
        ":orig_c_grammar",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
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
    name = "pnfc_parser_facade",
    srcs = ["PnfCParserFacade.java"],
    deps = [
        ":pnf_c_grammar",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
