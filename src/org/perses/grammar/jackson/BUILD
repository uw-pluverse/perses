load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_parser",
)

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "language_kind",
    srcs = [
        ":LanguageJackson.kt",
    ],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

pnf_convert(
    name = "normalize_jackson_parser_to_pnf",
    src = "JacksonParser.g4",
    out = "PnfJacksonParser.g4",
    start_rule_name = "start",
)

antlr_codegen_parser(
    name = "pnf_jackson_parser_codegen",
    java_pkg_name = "org.perses.grammar.jackson",
    parser_grammar_file = "PnfJacksonParser.g4",
    parser_java_file_name = "PnfJacksonParser.java",
)

kt_jvm_library(
    name = "jackson_lexer",
    srcs = [
        "JacksonAntlrBridge.kt",
        "JacksonLexer.kt",
    ],
    deps = [
        ":pnf_jackson_parser_codegen",
        "//:antlr_runtime",
        "//:jackson",
        "//src/org/perses/grammar:lexer_adaptor",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = [
        "JacksonParserFacade.kt",
    ],
    deps = [
        ":jackson_lexer",
        ":language_kind",
        ":pnf_jackson_parser_codegen",
        "//:guava",
        "//:jackson",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)
