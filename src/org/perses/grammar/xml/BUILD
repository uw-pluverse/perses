load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load(
    "//src/org/perses/grammar/adhoc:adhoc_grammar.bzl",
    "pnf_parser_facade_library",
)

package(default_visibility = [
    "//visibility:public",
])

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.xml",
    language_kind_full_name = "org.perses.grammar.xml.LanguageXML",
    lexer_file_name = "XMLLexer.g4",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "PnfXMLParserFacade",
    parser_file_name = "XMLParser.g4",
    start_rule_name = "document",
    token_names_of_identifiers = ["Name"],
    deps = [
        ":language_kind",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageXML.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
