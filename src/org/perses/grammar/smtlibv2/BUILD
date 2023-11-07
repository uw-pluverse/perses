package(default_visibility = [
    "//visibility:public",
])

load("//src/org/perses/grammar:antlr_util.bzl", "antlr_codegen_combined")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar/adhoc:adhoc_grammar.bzl",
    "orig_parser_facade_library",
    "pnf_parser_facade_library",
)

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

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.smtlibv2",
    language_kind_full_name = "org.perses.grammar.smtlibv2.LanguageSmtLibV2",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "SmtLibV2ParserFacade",
    parser_file_name = "SMTLIBv2.g4",
    start_rule_name = "start",
    token_names_of_identifiers = ["UndefinedSymbol"],
    deps = [
        ":language_kind",
    ],
)

orig_parser_facade_library(
    name = "orig_parser_facade",
    java_package_name = "org.perses.grammar.smtlibv2",
    language_kind_full_name = "org.perses.grammar.smtlibv2.LanguageSmtLibV2",
    output_jar_file_name = "orig_parser_facade.jar",
    parser_facade_class_simple_name = "OrigSmtLibV2ParserFacade",
    parser_file_name = "SMTLIBv2.g4",
    start_rule_name = "start",
    token_names_of_identifiers = ["UndefinedSymbol"],
    deps = [
        ":language_kind",
    ],
)
