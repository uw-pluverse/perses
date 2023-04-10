package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "tdtree",
    srcs = glob(["*.kt"]),
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)
