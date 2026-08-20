load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load(
    "//src/org/perses/grammar/adhoc:adhoc_grammar.bzl",
    "pnf_parser_facade_library",
)

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "language_kind",
    srcs = [
        "LanguageWebAssembly.kt",
    ],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

pnf_parser_facade_library(
    name = "parser_facade",
    include_auto_detected_identifier_token_types = False,
    java_package_name = "org.perses.grammar.wasm",
    language_kind_full_name = "org.perses.grammar.wasm.LanguageWebAssembly",
    lexer_file_name = "WatLexer.g4",
    output_jar_file_name = "pnf_parser_facade.jar",
    parser_facade_class_simple_name = "WebAssemblyParserFacade",
    parser_file_name = "WatParser.g4",
    start_rule_name = "start",
    token_names_of_identifiers = ["VAR"],
    deps = [
        ":language_kind",
    ],
)
