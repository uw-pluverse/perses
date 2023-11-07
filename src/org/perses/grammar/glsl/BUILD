package(default_visibility = [
    "//visibility:public",
])

load(
    "//antlropt/src/org/perses/antlr/pnf:pnf.bzl",
    "outline_implicit_token_defs",
)
load(
    "//src/org/perses/grammar/adhoc:adhoc_grammar.bzl",
    "orig_parser_facade_library",
    "pnf_parser_facade_library",
)
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

ito_dir = "implicit_token_outlined_dir"

ito_grammar = "%s/GLSL.g4" % ito_dir

start_rule_name = "translation_unit"

identifier_tokens = ["IDENTIFIER"]

outline_implicit_token_defs(
    name = "outline_implicit_token_defs_for_c",
    parser_input = "GLSL.g4",
    parser_output = ito_grammar,
    start_rule_name = "translation_unit",
)

orig_parser_facade_library(
    name = "orig_parser_facade",
    java_package_name = "org.perses.grammar.glsl",
    language_kind_full_name = "org.perses.grammar.glsl.LanguageGlsl",
    output_jar_file_name = "orig_parser_facade.jar",
    parser_facade_class_simple_name = "OrigGlslParserFacade",
    parser_file_name = ito_grammar,
    start_rule_name = start_rule_name,
    token_names_of_identifiers = identifier_tokens,
    deps = [
        ":language_kind",
    ],
)

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.glsl",
    language_kind_full_name = "org.perses.grammar.glsl.LanguageGlsl",
    output_jar_file_name = "pnf_parser_facade.jar",
    parser_facade_class_simple_name = "GlslParserFacade",
    parser_file_name = ito_grammar,
    start_rule_name = start_rule_name,
    token_names_of_identifiers = identifier_tokens,
    deps = [
        ":language_kind",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageGlsl.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
