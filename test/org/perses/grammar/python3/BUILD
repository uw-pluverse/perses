load("//test/org/perses:test.bzl", "cross_folder_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

cross_folder_golden_test(
    name = "test_pnf_python3_grammar",
    golden_file = "golden_pnf_python3.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/python3:normalize_python3_to_pnf",
)

kt_jvm_test(
    name = "Python3ParserFacadeTest",
    srcs = [
        "Python3ParserFacadeTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/python3:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)
