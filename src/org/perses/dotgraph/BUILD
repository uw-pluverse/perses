load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "dotgraph",
    srcs = [
        "DotGraph.kt",
        "TreeDotifier.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:parse_tree_with_parser",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
        "//src/org/perses/util/shell",
        "@maven//:org_apache_commons_commons_lang3",
    ],
)
