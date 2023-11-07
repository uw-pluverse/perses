package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load(
    "//src/org/perses/grammar/adhoc:adhoc_grammar.bzl",
    "orig_parser_facade_library",
    "pnf_parser_facade_library",
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageJava.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.java",
    language_kind_full_name = "org.perses.grammar.java.LanguageJava",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "JavaParserFacade",
    parser_file_name = "OrigJava8.g4",
    start_rule_name = "compilationUnit",
    token_names_of_identifiers = ["Identifier"],
    deps = [
        ":language_kind",
    ],
)

orig_parser_facade_library(
    name = "orig_parser_facade",
    java_package_name = "org.perses.grammar.java",
    language_kind_full_name = "org.perses.grammar.java.LanguageJava",
    output_jar_file_name = "orig_parser_facade.jar",
    parser_facade_class_simple_name = "OrigJavaParserFacade",
    parser_file_name = "OrigJava8.g4",
    start_rule_name = "compilationUnit",
    token_names_of_identifiers = ["Identifier"],
    deps = [
        ":language_kind",
    ],
)
