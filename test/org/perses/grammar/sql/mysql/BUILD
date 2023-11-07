load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "MySQLParserFacadeTest",
    srcs = ["MySQLParserFacadeTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/grammar/sql/mysql:parser_facade",
    ],
)
