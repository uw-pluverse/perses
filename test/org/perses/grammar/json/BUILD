load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "JsonParserTest",
    srcs = ["JsonParserTest.kt"],
    test_class = "org.perses.grammar.json.JsonParserTest",
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_grammar_util",
        "//src/org/perses/grammar/json:parser_facade",
        "//test/org/perses:test_util",
        "//test/org/perses/program:LanguageKindTestUtil",
    ],
)
