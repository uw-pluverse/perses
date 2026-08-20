load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_lexer",
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
        ":dyck_lexer",
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

# LineAwareDyckParser and PristineDyckParser both draw their token vocabulary from the
# shared DyckTokens lexer grammar (via `options { tokenVocab = DyckTokens; }`), so the
# token numbering is defined once and is identical across the two -- which is what lets the
# two generated parsers reuse the same hand-written DyckLexer. DyckTokens is passed to both
# pnf (to resolve token names) and codegen (to produce the .tokens the parser resolves);
# its generated lexer Java is discarded (real tokenizing is done by DyckLexer).
pnf_convert(
    name = "normalize_line_aware_dyck_parser_to_pnf",
    src = "LineAwareDyckParser.g4",
    out = "PnfLineAwareDyckParser.g4",
    lexer_grammar = "DyckTokens.g4",
    start_rule_name = "start",
)

antlr_codegen_parser(
    name = "pnf_line_aware_dyck_parser_codegen",
    java_pkg_name = "org.perses.grammar.dyck",
    lexer_grammar_file = "DyckTokens.g4",
    parser_grammar_file = "PnfLineAwareDyckParser.g4",
    parser_java_file_name = "PnfLineAwareDyckParser.java",
)

pnf_convert(
    name = "normalize_pristine_dyck_parser_to_pnf",
    src = "PristineDyckParser.g4",
    out = "PnfPristineDyckParser.g4",
    lexer_grammar = "DyckTokens.g4",
    start_rule_name = "start",
)

antlr_codegen_parser(
    name = "pnf_pristine_dyck_parser_codegen",
    java_pkg_name = "org.perses.grammar.dyck",
    lexer_grammar_file = "DyckTokens.g4",
    parser_grammar_file = "PnfPristineDyckParser.g4",
    parser_java_file_name = "PnfPristineDyckParser.java",
)

# Generates the DyckTokens lexer (token constants + ATN/vocabulary) from the shared token grammar.
# Unlike the codegen for the parsers -- which pass DyckTokens.g4 only to obtain its .tokens for
# tokenVocab and discard its lexer Java -- this target keeps DyckTokens.java so the hand-written
# DyckLexer can reference its token constants and build its LexerAtnWrapper from it, rather than
# depending on either generated parser.
antlr_codegen_lexer(
    name = "dyck_tokens_codegen",
    java_pkg_name = "org.perses.grammar.dyck",
    lexer_grammar_file = "DyckTokens.g4",
    lexer_java_file_name = "DyckTokens.java",
)

kt_jvm_library(
    name = "dyck_lexer",
    srcs = [
        "AdaptiveDyckConfigurationSelector.kt",
        "DyckLexer.kt",
    ],
    deps = [
        ":dyck_tokens_codegen",
        "//:antlr_runtime",
        "//:guava",
        "//src/org/perses/antlr/atn:lexer_wrapper",
        "//src/org/perses/grammar:lexer_adaptor",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = [
        "DyckLanguages.kt",
    ],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "parser_facade",
    srcs = [
        "DyckParserFacades.kt",
    ],
    deps = [
        ":dyck_lexer",
        ":language_kind",
        ":pnf_line_aware_dyck_parser_codegen",
        ":pnf_pristine_dyck_parser_codegen",
        "//src/org/perses/grammar/dyck:AbstractDyckParserFacade",
    ],
)
