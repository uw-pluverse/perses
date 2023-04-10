package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "atn",
    srcs = [
        "ATNSimulator.kt",
        "LexerAtnWrapper.kt",
    ],
    deps = [
        ":AbstractRandom",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/simulator/state",
        "//src/org/perses/antlr/atn/simulator/transition",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "AbstractRandom",
    srcs = [
        "AbstractDecisionMaker.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
    ],
)

kt_jvm_library(
    name = "atn_kt_utils",
    srcs = [
        "AtnKtUtils.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/util:simple_stack_and_queue",
    ],
)
