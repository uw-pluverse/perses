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
    name = "AbstractDyckParserFacade",
    srcs = [
        "AbstractDyckParserFacade.kt",
    ],
    deps = [
        ":pnf_dyck_parser_codegen",
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

pnf_convert(
    name = "normalize_dyck_parser_to_pnf",
    src = "DyckParser.g4",
    out = "PnfDyckParser.g4",
    start_rule_name = "start",
)

antlr_codegen_parser(
    name = "pnf_dyck_parser_codegen",
    java_pkg_name = "org.perses.grammar.dyck",
    parser_grammar_file = "PnfDyckParser.g4",
    parser_java_file_name = "PnfDyckParser.java",
)

kt_jvm_library(
    name = "AbstractDyckLexer",
    srcs = [
        "AbstractDyckLexer.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:lexer_adaptor",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "dyck_lexers",
    srcs = [
        "BraceDyckLexer.kt",
        "BraceParenthesisDyckLexer.kt",
    ],
    deps = [
        ":AbstractDyckLexer",
        ":pnf_dyck_parser_codegen",
        "//:antlr_runtime",
        "//src/org/perses/grammar:lexer_adaptor",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = [
        "LanguageBraceDyck.kt",
        "LanguageBraceParenthesisDyck.kt",
    ],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = [
        "BraceDyckParserFacade.kt",
        "BraceParenthesisDyckParserFacade.kt",
    ],
    deps = [
        ":dyck_lexers",
        ":language_kind",
        ":pnf_dyck_parser_codegen",
        "//src/org/perses/grammar/dyck:AbstractDyckParserFacade",
    ],
)
