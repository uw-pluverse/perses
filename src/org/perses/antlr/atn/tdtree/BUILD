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
        "//src/org/perses/antlr/atn:atn_kt_utils",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)
