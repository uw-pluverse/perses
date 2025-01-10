package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "TokenCanonicalizerTest",
    srcs = ["TokenCanonicalizerTest.kt"],
    associates = [
        "//src/org/perses/reduction/reducer/trec",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)
