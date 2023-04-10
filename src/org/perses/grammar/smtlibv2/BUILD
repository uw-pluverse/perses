package(default_visibility = [
    "//visibility:public",
])

load("//src/org/perses/grammar:antlr_util.bzl", "antlr_codegen_combined")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")

pnf_convert(
    name = "normalize_smtlibv2_to_pnf",
    src = "SMTLIBv2.g4",
    out = "PnfSMTLIBv2.g4",
    start_rule_name = "start",
)

antlr_codegen_combined(
    name = "pnf_smtlibv2_grammar",
    grammar_file = "PnfSMTLIBv2.g4",
    java_pkg_name = "org.perses.grammar.smtlibv2",
    lexer_java_file_name = "PnfSMTLIBv2Lexer.java",
    parser_java_file_name = "PnfSMTLIBv2Parser.java",
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageSmtLibV2.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

java_library(
    name = "parser_facade",
    srcs = ["SmtLibV2ParserFacade.java"],
    deps = [
        ":language_kind",
        ":pnf_smtlibv2_grammar",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)
