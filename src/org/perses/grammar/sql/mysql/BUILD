package(default_visibility = [
    "//visibility:public",
])

load(
    "//antlropt/src/org/perses/antlr/pnf:pnf.bzl",
    "outline_implicit_token_defs",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//src/org/perses/grammar/adhoc:adhoc_grammar.bzl", "pnf_parser_facade_library")

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageMySQL.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)

ito_dir = "implicit_token_outlined_dir"

ito_parser_file = ito_dir + "/" + "MySqlParser.g4"

ito_lexer_file = ito_dir + "/" + "MySqlLexer.g4"

outline_implicit_token_defs(
    name = "outline_implicit_token_defs_for_mysql",
    lexer_input = "preprocessed/MySqlLexer.g4",
    lexer_output = ito_lexer_file,
    parser_input = "preprocessed/MySqlParser.g4",
    parser_output = ito_parser_file,
    start_rule_name = "root",
)

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.grammar.sql.mysql",
    language_kind_full_name = "org.perses.grammar.sql.mysql.LanguageMySQL",
    lexer_file_name = ito_lexer_file,
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "MySQLParserFacade",
    parser_file_name = ito_parser_file,
    start_rule_name = "root",
    token_names_of_identifiers = ["ID"],
    deps = [
        ":language_kind",
    ],
)
