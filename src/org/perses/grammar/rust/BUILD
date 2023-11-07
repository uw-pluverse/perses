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

antlr_codegen_combined(
    name = "orig_rust_grammar",
    grammar_file = "Rust.g4",
    java_pkg_name = "org.perses.grammar.rust",
    lexer_java_file_name = "RustLexer.java",
    parser_java_file_name = "RustParser.java",
)

pnf_convert(
    name = "normalize_rust_to_pnf",
    src = "Rust.g4",
    out = "PnfRust.g4",
    start_rule_name = "crate",
)

antlr_codegen_combined(
    name = "pnf_rust_grammar",
    grammar_file = "PnfRust.g4",
    java_pkg_name = "org.perses.grammar.rust",
    lexer_java_file_name = "PnfRustLexer.java",
    parser_java_file_name = "PnfRustParser.java",
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageRust.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.rust",
    language_kind_full_name = "org.perses.grammar.rust.LanguageRust",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "PnfRustParserFacade",
    parser_file_name = "Rust.g4",
    start_rule_name = "crate",
    token_names_of_identifiers = ["Ident"],
    deps = [
        ":language_kind",
    ],
)

orig_parser_facade_library(
    name = "orig_parser_facade",
    java_package_name = "org.perses.grammar.rust",
    language_kind_full_name = "org.perses.grammar.rust.LanguageRust",
    output_jar_file_name = "orig_parser_facade.jar",
    parser_facade_class_simple_name = "OrigRustParserFacade",
    parser_file_name = "Rust.g4",
    start_rule_name = "crate",
    token_names_of_identifiers = ["Ident"],
    deps = [
        ":language_kind",
    ],
)
