package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

java_library(
    name = "grammar_facade",
    srcs = [
        "AbstractDefaultParserFacade.java",
        "AbstractParserFacade.java",
        "AntlrFailureException.java",
        "FailOnErrorAntlrErrorListener.java",
    ],
    deps = [
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/program",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)

java_library(
    name = "facade_factory",
    srcs = ["ParserFacadeFactory.java"],
    deps = [
        ":grammar_facade",
        "//src/org/perses:language_kind",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//src/org/perses/grammar/java:java_parser_facade",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
    ],
)

java_binary(
    name = "antlr_tool",
    main_class = "org.antlr.v4.Tool",
    visibility = ["//visibility:public"],
    runtime_deps = ["@maven//:org_antlr_antlr4"],
)
