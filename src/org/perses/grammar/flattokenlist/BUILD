load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_parser",
)

package(default_visibility = [
    "//visibility:public",
])

pnf_convert(
    name = "normalize_flat_token_list_parser_to_pnf",
    src = "FlatTokenList.g4",
    out = "PnfFlatTokenList.g4",
    start_rule_name = "start",
)

antlr_codegen_parser(
    name = "pnf_flat_token_list_parser_codegen",
    java_pkg_name = "org.perses.grammar.flattokenlist",
    parser_grammar_file = "PnfFlatTokenList.g4",
    parser_java_file_name = "PnfFlatTokenList.java",
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageFlatTokenList.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "lexer",
    srcs = ["FlatTokenListLexer.kt"],
    deps = [
        ":pnf_flat_token_list_parser_codegen",
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/grammar:lexer_adaptor",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = ["FlatTokenListParserFacade.kt"],
    deps = [
        ":language_kind",
        ":lexer",
        ":pnf_flat_token_list_parser_codegen",
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)
