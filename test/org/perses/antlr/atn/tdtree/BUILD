load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "TDTreeTest",
    srcs = [
        "TDTreeTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/antlr/atn:lexer_wrapper",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
        "//test/org/perses/antlr/atn:OrigC",
    ],
)
