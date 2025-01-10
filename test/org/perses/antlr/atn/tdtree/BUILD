load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "TDTreeTest",
    srcs = [
        "TDTreeTest.kt",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/antlr/atn/nfa",
        "//test/org/perses/antlr/atn:OrigC",
    ],
)
