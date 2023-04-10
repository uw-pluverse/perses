package(default_visibility = [
    "//visibility:public",
])

load(
    "//src/org/perses/grammar:antlr_util.bzl",
    "antlr_codegen_combined",
    "antlr_codegen_lexer",
)
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "AstSimulatorTest",
    srcs = [
        "AstSimulatorTest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:truth",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/simulator/ast",
        "//test/org/perses/antlr/atn:RandomMock",
        "//test/org/perses/antlr/atn:TestLexer",
        "//test/org/perses/antlr/atn:TestUtil",
    ],
)
