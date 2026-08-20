load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = ["//visibility:public"])

kt_jvm_test(
    name = "FlatTokenListLexerTest",
    srcs = ["FlatTokenListLexerTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/flattokenlist:parser_facade",
    ],
)
