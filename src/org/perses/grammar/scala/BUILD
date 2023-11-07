package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/src/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

antlr_codegen_combined(
    name = "orig_scala_grammar",
    grammar_file = "Scala.g4",
    java_pkg_name = "org.perses.grammar.scala",
    lexer_java_file_name = "ScalaLexer.java",
    parser_java_file_name = "ScalaParser.java",
)

pnf_convert(
    name = "normalize_scala_to_pnf",
    src = "Scala.g4",
    out = "PnfScala.g4",
    start_rule_name = "compilationUnit",
)

antlr_codegen_combined(
    name = "pnf_scala_grammar",
    grammar_file = "PnfScala.g4",
    java_pkg_name = "org.perses.grammar.scala",
    lexer_java_file_name = "PnfScalaLexer.java",
    parser_java_file_name = "PnfScalaParser.java",
)

kt_jvm_library(
    name = "parser_facade",
    srcs = ["PnfScalaParserFacade.kt"],
    deps = [
        ":language_kind",
        ":orig_scala_grammar",
        ":pnf_scala_grammar",
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageScala.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
