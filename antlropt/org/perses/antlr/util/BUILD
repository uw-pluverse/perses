package(default_visibility = ["//visibility:public"])

java_library(
    name = "util",
    srcs = ["Util.java"],
    deps = [
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "lexer_parser_combiner",
    srcs = ["LexerParserCombiner.java"],
    deps = [
        ":util",
        "//antlropt/org/perses/antlr/ast",
        "@maven//:com_beust_jcommander",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_guava_guava",
    ],
)



java_binary(
    name = "combine_lexer_parser_bin",
    main_class = "org.perses.antlr.util.LexerParserCombiner",
    runtime_deps=[":lexer_parser_combiner"]
)