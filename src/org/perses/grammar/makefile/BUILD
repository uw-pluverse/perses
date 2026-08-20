load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//src/org/perses/grammar/adhoc:adhoc_grammar.bzl", "pnf_parser_facade_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageMakefile.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

pnf_parser_facade_library(
    name = "parser_facade",
    include_auto_detected_identifier_token_types = False,
    java_package_name = "org.perses.grammar.makefile",
    language_kind_full_name = "org.perses.grammar.makefile.LanguageMakefile",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "MakefileParserFacade",
    parser_file_name = "MakefileGrammar.g4",
    start_rule_name = "makefile",
    token_names_of_identifiers = [],
    deps = [
        ":language_kind",
    ],
)
