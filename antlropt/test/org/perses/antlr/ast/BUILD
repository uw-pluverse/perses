load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "PersesAstParserTest",
    srcs = ["PersesAstParserTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "@maven//:org_antlr_antlr4",
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
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//test/org/perses/antlr:GrammarTestingUtility",
        "@maven//:org_antlr_antlr4",
    ],
)
