package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//src/org/perses/grammar/adhoc:adhoc_grammar.bzl", "pnf_parser_facade_library")

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageJson.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.json",
    language_kind_full_name = "org.perses.grammar.json.LanguageJson",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "JsonParserFacade",
    parser_file_name = "JSON.g4",
    start_rule_name = "json",
    token_names_of_identifiers = ["STRING"],
    deps = [
        ":language_kind",
    ],
)
