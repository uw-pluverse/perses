package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_lexer",
    "antlr_codegen_parser",
)
load("//src/org/perses/grammar/adhoc:adhoc_grammar.bzl", "pnf_parser_facade_library")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

pnf_convert(
    name = "normalize_ruby_to_pnf",
    src = "RubyParser.g4",
    out = "PnfRubyParser.g4",
    lexer_grammar = "RubyLexer.g4",
    start_rule_name = "compilation_unit",
)

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.ruby",
    language_kind_full_name = "org.perses.grammar.ruby.LanguageRuby",
    lexer_file_name = "RubyLexer.g4",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "PnfRubyParserFacade",
    parser_file_name = "RubyParser.g4",
    start_rule_name = "compilation_unit",
    token_names_of_identifiers = ["Identifier"],
    deps = [
        ":language_kind",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageRuby.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

filegroup(
    name = "grammar_files",
    srcs = [
        "RubyLexer.g4",
        "RubyParser.g4",
    ],
)
