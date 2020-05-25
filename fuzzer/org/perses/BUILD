package(default_visibility = [
    "//fuzzer_test/org/perses:__pkg__",
    "//src/org/perses/grammar:__pkg__",
])

java_library(
    name = "perses_fuzzer",
    srcs = ["Fuzzer.java"],
    #    main_class = "org.perses.fuzzer.Fuzzer",
    deps = [
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
