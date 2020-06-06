package(default_visibility = [
    "//fuzzer_test/org/perses:__pkg__",
    "//src/org/perses/grammar:__pkg__",
])

java_binary(
    name = "perses_fuzzer",
    srcs = ["Fuzzer.java"],
    main_class = "org.perses.fuzzer.Fuzzer",
    deps = [
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/tree/spar",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
