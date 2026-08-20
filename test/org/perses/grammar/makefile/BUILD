load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "MakefileParserFacadeTest",
    srcs = ["MakefileParserFacadeTest.kt"],
    data = glob(["real_world_makefiles/**"]),
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:flogger",
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/makefile:parser_facade",
        "//test/org/perses:test_util",
        "@maven//:junit_junit",
    ],
)
