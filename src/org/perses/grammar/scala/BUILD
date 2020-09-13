package(default_visibility = [
    "//visibility:public",
])

load("//antlropt/org/perses/antlr/pnf:pnf.bzl", "pnf_convert")
load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
)

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

java_library(
    name = "pnfscala_parser_facade",
    srcs = ["PnfScalaParserFacade.java"],
    deps = [
        ":orig_scala_grammar",
        ":pnf_scala_grammar",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
