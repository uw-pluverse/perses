package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "state",
    srcs = glob(["*.kt"]),
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/antlr/atn:AbstractRandom",
        "//src/org/perses/antlr/atn:atn_kt_utils",
        "//src/org/perses/antlr/atn/simulator:simulator_registry_interface",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/util",
    ],
)
