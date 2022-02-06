load("//test/org/perses:test.bzl", "cross_folder_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

cross_folder_golden_test(
    name = "test_pnf_ruby_grammar",
    golden_file = "golden_pnf_ruby.g4",
    test_file_in_other_folders = "//src/org/perses/grammar/ruby:normalize_ruby_to_pnf",
)

kt_jvm_test(
    name = "RubyParserFacadeTest",
    srcs = [
        "RubyParserFacadeTest.kt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/ruby:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
