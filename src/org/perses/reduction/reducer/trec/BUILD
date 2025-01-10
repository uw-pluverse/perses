load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "trec",
    srcs = [
        "TokenCanonicalizer.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/antlr/atn",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reducer_context_interface",
        "//src/org/perses/reduction/reducer/vulcan",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:minimal_spartree_generator",
        "//src/org/perses/util",
    ],
)
