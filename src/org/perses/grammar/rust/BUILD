package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
)
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

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

java_library(
    name = "pnfrust_parser_facade",
    srcs = ["PnfRustParserFacade.java"],
    deps = [
        ":language_kind",
        ":orig_rust_grammar",
        ":pnf_rust_grammar",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageRust.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
