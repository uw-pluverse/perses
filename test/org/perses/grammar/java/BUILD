load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "OptJavaParserTest",
    srcs = ["OptJavaParserTest.kt"],
    test_class = "org.perses.grammar.java.OptJavaParserTest",
    deps = [
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/java:parser_facade",
    ],
)
