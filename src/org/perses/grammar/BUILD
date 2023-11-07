package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "antlr_exception_strategy",
    srcs = [
        "AntlrFailureException.kt",
        "ExceptionErrorStrategy.kt",
        "FailOnErrorAntlrErrorListener.kt",
    ],
    deps = [
        "//:antlr_runtime",
    ],
)

kt_jvm_library(
    name = "grammar_facade",
    srcs = [
        "AbstractDefaultParserFacade.kt",
        "AbstractParserFacade.kt",
        "ParserFacadeTag.kt",
    ],
    deps = [
        ":antlr_exception_strategy",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//src/org/perses/antlr:antlr_grammar_info",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/antlr:util",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
    ],
)

kt_jvm_library(
    name = "facade_factory",
    srcs = [
        "AbstractParserFacadeFactory.kt",
        "CompositeParserFacadeFactory.kt",
        "SingleParserFacadeFactory.kt",
    ],
    deps = [
        ":grammar_facade",
        "//:flogger",
        "//:guava",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/cpp:parser_facade",
        "//src/org/perses/grammar/glsl:parser_facade",
        "//src/org/perses/grammar/go:parser_facade",
        "//src/org/perses/grammar/java:parser_facade",
        "//src/org/perses/grammar/javascript:parser_facade",
        "//src/org/perses/grammar/php:parser_facade",
        "//src/org/perses/grammar/python3:parser_facade",
        "//src/org/perses/grammar/ruby:parser_facade",
        "//src/org/perses/grammar/rust:parser_facade",
        "//src/org/perses/grammar/scala:parser_facade",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//src/org/perses/grammar/solidity/preprocessed:parser_facade",
        "//src/org/perses/grammar/sql/mysql:parser_facade",
        "//src/org/perses/grammar/sql/sqlite:parser_facade",
        "//src/org/perses/grammar/sysverilog:parser_facade",
        "//src/org/perses/program:language_kind",
    ],
)

java_binary(
    name = "antlr_tool",
    main_class = "org.antlr.v4.Tool",
    visibility = ["//visibility:public"],
    runtime_deps = ["//:antlr_tool"],
)
