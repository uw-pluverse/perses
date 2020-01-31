package(default_visibility = [
    "//src/org/perses/grammar:__pkg__",
    "//test/org/perses:__subpackages__",
])

load("//src/org/perses/grammar:antlr_util.bzl", "antlr_codegen")

antlr_codegen(
    name = "opt_java_grammar",
    grammar_file = "OptJava8.g4",
    java_pkg_name = "org.perses.grammar.java",
)

antlr_codegen(
    name = "orig_java_grammar",
    grammar_file = "OrigJava8.g4",
    java_pkg_name = "org.perses.grammar.java",
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
