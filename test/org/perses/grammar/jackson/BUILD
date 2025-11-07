load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "JacksonParserFacadeTest",
    srcs = [
        "JacksonParserFacadeTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/jackson:parser_facade",
        "//src/org/perses/program/printer:YamlTokenizedProgramPrinter",
        "//src/org/perses/spartree",
    ],
)
