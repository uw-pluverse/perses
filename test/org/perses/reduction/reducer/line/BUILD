load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "TopFormFlatChunkerTest",
    srcs = ["TopFormFlatChunkerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/reduction/reducer/line:topformflat_chunker",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
    ],
)
