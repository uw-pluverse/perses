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
        "//src/org/perses/util",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TolerantParserFacadeTest",
    srcs = ["TolerantParserFacadeTest.kt"],
    deps = [
        "//:antlr_runtime",
        "//:truth",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:optc_parser_facade",
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

kt_jvm_test(
    name = "IdentifierTokenAuditTest",
    srcs = [
        "IdentifierTokenAuditTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/antlr:antlr_type_wrappers",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

kt_jvm_test(
    name = "TolerantFallbackParserFacadesTest",
    srcs = ["TolerantFallbackParserFacadesTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar:tolerant_fallback_facades",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/grammar/line:parser_facade",
        "//src/org/perses/grammar/onetoken:parser_facade",
    ],
)
