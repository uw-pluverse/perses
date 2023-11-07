load("//test/org/perses:test.bzl", "cross_folder_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

cross_folder_golden_test(
    name = "test_pnf_php_grammar",
    golden_file = "golden_pnf_php.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/php:normalize_php_to_pnf",
)

kt_jvm_test(
    name = "PhpParserFacadeTest",
    srcs = [
        "PhpParserFacadeTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/php:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)
