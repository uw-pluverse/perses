package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "NFATest",
    srcs = [
        "NFATest.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:truth",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/antlr/atn/nfa",
        "//test/org/perses/antlr/atn:RandomMock",
        "//test/org/perses/antlr/atn:TestLexer",
        "//test/org/perses/antlr/atn:TestUtil",
    ],
)
