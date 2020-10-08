package(default_visibility = [
    "//visibility:public",
])

load("//src/org/perses/grammar:antlr_util.bzl", "antlr_codegen_combined")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

antlr_codegen_combined(
    name = "opt_java_grammar",
    grammar_file = "OptJava8.g4",
    java_pkg_name = "org.perses.grammar.java",
    lexer_java_file_name = "OptJava8Lexer.java",
    parser_java_file_name = "OptJava8Parser.java",
)

antlr_codegen_combined(
    name = "orig_java_grammar",
    grammar_file = "OrigJava8.g4",
    java_pkg_name = "org.perses.grammar.java",
    lexer_java_file_name = "OrigJava8Lexer.java",
    parser_java_file_name = "OrigJava8Parser.java",
)

java_library(
    name = "java_parser_facade",
    srcs = ["JavaParserFacade.java"],
    deps = [
        ":language_kind",
        ":opt_java_grammar",
        ":orig_java_grammar",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program:language_kind",
        "@maven//:com_google_flogger_flogger",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageJava.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
