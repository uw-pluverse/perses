package(default_visibility = [
    "//src/org/perses/grammar:__pkg__",
    "//test/org/perses:__subpackages__",
])

load("//src/org/perses/grammar:antlr_util.bzl", "antlr_codegen_combined")

antlr_codegen_combined(
    name = "opt_java_grammar",
    java_pkg_name = "org.perses.grammar.java",
    lexer_java_file_name = "OptJava8Lexer.java",
    grammar_file = "OptJava8.g4",
    parser_java_file_name = "OptJava8Parser.java",
)

antlr_codegen_combined(
    name = "orig_java_grammar",
    java_pkg_name = "org.perses.grammar.java",
    lexer_java_file_name = "OrigJava8Lexer.java",
    grammar_file = "OrigJava8.g4",
    parser_java_file_name = "OrigJava8Parser.java",
)

java_library(
    name = "java_parser_facade",
    srcs = ["JavaParserFacade.java"],
    deps = [
        ":opt_java_grammar",
        ":orig_java_grammar",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
