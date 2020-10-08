package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_lexer",
    "antlr_codegen_parser",
)
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

pnf_convert(
    name = "normalize_go_to_pnf",
    src = "GoParser.g4",
    out = "PnfGoParser.g4",
    start_rule_name = "sourceFile",
)
#
#antlr_codegen(
#    name = "orig_go_grammar",
#    parser_grammar_file = "GoParser.g4",
#    parser_java_file_name = "GoParser.java",
#    lexer_java_file_name = "GoLexer.java",
#    lexer_grammar_file = "GoLexer.g4",
#    aux_java_files = ["GoParserBase.java"],
#    java_pkg_name = "org.perses.grammar.go"
#)

antlr_codegen_lexer(
    name = "go_lexer",
    java_pkg_name = "org.perses.grammar.go",
    lexer_grammar_file = "GoLexer.g4",
    lexer_java_file_name = "GoLexer.java",
)

java_library(
    name = "go_parser_base",
    srcs = ["GoParserBase.java"],
    deps = [
        ":go_lexer",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

antlr_codegen_parser(
    name = "orig_go_parser",
    java_pkg_name = "org.perses.grammar.go",
    lexer_grammar_file = "GoLexer.g4",
    parser_grammar_file = "GoParser.g4",
    parser_java_file_name = "GoParser.java",
    deps = [
        ":go_lexer",
        ":go_parser_base",
    ],
)

antlr_codegen_parser(
    name = "pnf_go_parser",
    java_pkg_name = "org.perses.grammar.go",
    lexer_grammar_file = "GoLexer.g4",
    parser_grammar_file = "PnfGoParser.g4",
    parser_java_file_name = "PnfGoParser.java",
    deps = [
        ":go_lexer",
        ":go_parser_base",
    ],
)

java_library(
    name = "pnfgo_parser_facade",
    srcs = ["PnfGoParserFacade.java"],
    deps = [
        ":go_lexer",
        ":languge_kind",
        ":orig_go_parser",
        ":pnf_go_parser",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

kt_jvm_library(
    name = "languge_kind",
    srcs = ["LanguageGo.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
