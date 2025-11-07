load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "LatraPatternTest",
    srcs = [
        "LatraPatternTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//src/org/perses/grammar/wasm:parser_facade",
        "//src/org/perses/reduction/reducer/latra/language",
    ],
)

kt_jvm_test(
    name = "LatraTransformationDefinitionTest",
    srcs = [
        "LatraTransformationDefinitionTest.kt",
    ],
    associates = ["//src/org/perses/reduction/reducer/latra/c"],
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
    associates = ["//src/org/perses/reduction/reducer/latra/c"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//test/org/perses:test_util",
    ],
)
