load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "ParserFacadeTest",
    srcs = ["ParserFacadeTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/scala_helloworld",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/scala:parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "ParserFacadeFactoryTest",
    srcs = [
        "ParserFacadeFactoryTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
    ],
)
