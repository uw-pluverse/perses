package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "simulator_registry_interface",
    srcs = [
        "AbstractSimulatorRegistry.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/antlr/atn:AbstractRandom",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/util",
    ],
)
