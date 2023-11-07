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
    name = "solidity_lexer",
    java_pkg_name = "org.perses.grammar.solidity.preprocessed",
    lexer_grammar_file = "SolidityLexer.g4",
    lexer_java_file_name = "SolidityLexer.java",
)

antlr_codegen_parser(
    name = "orig_solidity_parser",
    java_pkg_name = "org.perses.grammar.solidity.preprocessed",
    lexer_grammar_file = "SolidityLexer.g4",
    parser_grammar_file = "Solidity.g4",
    parser_java_file_name = "SolidityParser.java",
    deps = [
        ":solidity_lexer",
    ],
)

pnf_convert(
    name = "normalize_solidity_to_pnf",
    src = "Solidity.g4",
    out = "PnfSolidity.g4",
    lexer_grammar = "SolidityLexer.g4",
    start_rule_name = "sourceUnit",
)

antlr_codegen_parser(
    name = "pnf_solidity_grammar",
    java_pkg_name = "org.perses.grammar.solidity.preprocessed",
    lexer_grammar_file = "SolidityLexer.g4",
    parser_grammar_file = "PnfSolidity.g4",
    parser_java_file_name = "PnfSolidityParser.java",
)

kt_jvm_library(
    name = "parser_facade",
    srcs = ["PnfSolidityParserFacade.kt"],
    deps = [
        ":orig_solidity_parser",
        ":pnf_solidity_grammar",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/solidity:language_kind",
        "//src/org/perses/program:language_kind",
    ],
)

filegroup(
    name = "grammar_files",
    srcs = [
        "Solidity.g4",
        "SolidityLexer.g4",
    ],
)
