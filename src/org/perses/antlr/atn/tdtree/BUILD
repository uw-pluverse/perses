load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "tdtree",
    srcs = glob(["*.kt"]),
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/spartree:tree_node",
        "//src/org/perses/spartree:tree_node_filter_result",
        "//src/org/perses/util",
    ],
)
