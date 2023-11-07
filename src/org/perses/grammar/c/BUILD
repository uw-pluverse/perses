package(default_visibility = [
    "//visibility:public",
])

load(
    "//antlropt/src/org/perses/antlr/pnf:pnf.bzl",
    "outline_implicit_token_defs",
    "pnf_convert",
)
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load(
    "//src/org/perses/grammar/adhoc:adhoc_grammar.bzl",
    "orig_parser_facade_library",
)

implicit_token_outlined_dir = "implicit_token_outlined_dir"

ito_parser_file = "%s/OrigC.g4" % implicit_token_outlined_dir

outline_implicit_token_defs(
    name = "outline_implicit_token_defs_for_c",
    parser_input = "OrigC.g4",
    parser_output = ito_parser_file,
    start_rule_name = "compilationUnit",
)

outline_implicit_token_defs(
    name = "outline_implicit_token_defs_for_optc",
    parser_input = "OptC.g4",
    parser_output = "%s/OptC.g4" % implicit_token_outlined_dir,
    start_rule_name = "compilationUnit",
)

antlr_codegen_combined(
    name = "opt_c_grammar",
    grammar_file = "%s/OptC.g4" % implicit_token_outlined_dir,
    java_pkg_name = "org.perses.grammar.c",
    lexer_java_file_name = "OptCLexer.java",
    parser_java_file_name = "OptCParser.java",
)

orig_parser_facade_library(
    name = "orig_parser_facade",
    java_package_name = "org.perses.grammar.c",
    language_kind_full_name = "org.perses.grammar.c.LanguageC",
    output_jar_file_name = "orig_parser_facade.jar",
    parser_facade_class_simple_name = "OrigCParserFacade",
    parser_file_name = ito_parser_file,
    start_rule_name = "compilationUnit",
    token_names_of_identifiers = ["Identifier"],
    deps = [
        ":language_kind",
    ],
)

antlr_codegen_combined(
    name = "orig_c_grammar",
    grammar_file = ito_parser_file,
    java_pkg_name = "org.perses.grammar.c",
    lexer_java_file_name = "OrigCLexer.java",
    parser_java_file_name = "OrigCParser.java",
)

kt_jvm_library(
    name = "optc_parser_facade",
    srcs = ["CParserFacade.kt"],
    deps = [
        ":language_kind",
        ":opt_c_grammar",
        ":orig_c_grammar",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)

pnf_convert(
    name = "normalize_c_to_pnf",
    src = ito_parser_file,
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

kt_jvm_library(
    name = "parser_facade",
    srcs = ["PnfCParserFacade.kt"],
    deps = [
        ":language_kind",
        ":pnf_c_grammar",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)

filegroup(
    name = "implicit_token_outlined",
    srcs = [ito_parser_file],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageC.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

exports_files([
    "OrigC.g4",
])
