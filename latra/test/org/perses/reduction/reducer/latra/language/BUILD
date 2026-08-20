load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "LatraPatternTest",
    srcs = [
        "LatraPatternTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//latra/src/org/perses/reduction/reducer/latra/language",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//src/org/perses/grammar/wasm:parser_facade",
    ],
)

kt_jvm_test(
    name = "LatraTransformationDefinitionTest",
    srcs = [
        "LatraTransformationDefinitionTest.kt",
    ],
    associates = ["//latra/src/org/perses/reduction/reducer/latra/c"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/c:orig_parser_facade",
    ],
)

kt_jvm_test(
    name = "WhereClauseTest",
    srcs = [
        "WhereClauseTest.kt",
    ],
    associates = ["//latra/src/org/perses/reduction/reducer/latra/c"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//test/org/perses:test_util",
    ],
)
