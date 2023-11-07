load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load("//test/org/perses:test.bzl", "copy", "cross_folder_golden_test")

cross_folder_golden_test(
    name = "test_pnf_smtlib2_grammar",
    golden_file = "golden_pnf_smtlib2.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/smtlibv2:normalize_smtlibv2_to_pnf",
)

kt_jvm_test(
    name = "PnfSmtLibv2ParserFacadeTest",
    srcs = ["PnfSmtLibv2ParserFacadeTest.kt"],
    data = [
        "//test_data/smtlibv2_programs",
    ],
    shard_count = 1,
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/smtlibv2:orig_parser_facade",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)
