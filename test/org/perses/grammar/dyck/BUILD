load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "VariousDyckParserFacadeTest",
    srcs = [
        "VariousDyckParserFacadeTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:opt_c_grammar",
        "//src/org/perses/grammar/dyck:parser_facade",
        "//src/org/perses/spartree",
    ],
)
