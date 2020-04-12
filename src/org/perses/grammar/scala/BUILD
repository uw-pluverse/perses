package(default_visibility = [
    "//src/org/perses/grammar:__pkg__",
    "//test/org/perses:__subpackages__",
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
