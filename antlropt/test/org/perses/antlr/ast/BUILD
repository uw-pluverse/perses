load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "PersesAstParserTest",
    srcs = ["PersesAstParserTest.kt"],
    data = [
        "//src/org/perses/grammar/php:grammar_files",
    ],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:kotlin_stdib",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
    ],
)

kt_jvm_test(
    name = "RuleNameRegistryTest",
    srcs = [
        "RuleNameRegistryTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
    ],
)

kt_jvm_test(
    name = "PersesSequenceAstTest",
    srcs = ["PersesSequenceAstTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//test/org/perses/antlr:GrammarTestingUtility",
    ],
)
