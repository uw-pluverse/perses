load("//test/org/perses:test.bzl", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

genrule(
    name = "cp_pnf_go_grammar",
    outs = ["pnf_go_grammar.g4"],
    srcs = ["//src/org/perses/grammar/go:normalize_go_to_pnf"],
    cmd = "cp \"$<\" \"$@\""
)

golden_test(
    name = "test_pnf_go_grammar",
    test_file = "pnf_go_grammar.g4",
    golden_file = "golden_pnf_go.g4"
)


kt_jvm_test(
    name = "PnfGoParserFacadeTest",
    size = "enormous",  # This is a slow test.
    srcs = ["PnfGoParserFacadeTest.kt"],
    data = [],
    shard_count = 7,
    test_class = "org.perses.grammar.go.PnfGoParserFacadeTest",
    deps = [
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/go:pnfgo_parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
