load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

#
#kt_jvm_test(
#    name = "LanguageCTest",
#    srcs = [
#        "LanguageCTest.kt",
#    ],
#    deps = [
#        "//src/org/perses/grammar/c:language_kind",
#    "//:truth",
#    "//:flogger",
#
#    "//:guava",
#    ],
#)

kt_jvm_test(
    name = "PnfCppParserFacadeTest",
    srcs = ["PnfCppParserFacadeTest.kt"],
    data = [
        "//test/org/perses/benchmark_toys/cpp_print:files",
    ],
    shard_count = 1,
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar/c:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)

#kt_jvm_test(
#    name = "PreprocessedCFileParserTest",
#    srcs = ["PreprocessedCFileParserTest.kt"],
#    data = ["//test_data/c_programs/preprocessed_files"],
#    test_class = "org.perses.grammar.c.PreprocessedCFileParserTest",
#    deps = [
#        "//src/org/perses/antlr:util",
#        "//src/org/perses/grammar/c:pnfc_parser_facade",
#        "//test/org/perses:test_util",
#    "//:truth",
#    "//:flogger",
#    "//:guava",
#        "//:antlr_tool",
#        "//:antlr_runtime",
#    ],
#)
