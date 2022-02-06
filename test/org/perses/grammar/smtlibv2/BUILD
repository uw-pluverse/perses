load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//test/org/perses:test.bzl", "copy", "cross_folder_golden_test")

cross_folder_golden_test(
    name = "test_pnf_smtlib2_grammar",
    golden_file = "golden_pnf_smtlib2.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/smtlibv2:normalize_smtlibv2_to_pnf",
)

kt_jvm_test(
    name = "PnfSmtlibv2ParserFacadeTest",
    srcs = ["PnfSmtLibv2ParserFacadeTest.kt"],
    data = [
        "//test_data/smtlibv2_programs",
    ],
    shard_count = 1,
    test_class = "org.perses.grammar.smtlibv2.PnfSmtLibv2ParserFacadeTest",
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
