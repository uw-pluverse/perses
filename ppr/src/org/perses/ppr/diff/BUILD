package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "ppr_diff_utils",
    srcs = ["PPRDiffUtils.kt"],
    deps = [
        "//:gumtree",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/spartree",
        "//src/org/perses/util:perses_diffutil",
    ],
)
