load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "ParserFacadeTest",
    srcs = ["ParserFacadeTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/scala_helloworld",
    ],
    test_class = "org.perses.grammar.ParserFacadeTest",
    deps = [
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/tree/spar",
        "//test/org/perses:test_util",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4_runtime",
    ],
)
