load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "lexer_wrapper",
    srcs = [
        "ATNSimulator.kt",
        "LexerAtnWrapper.kt",
    ],
    deps = [
        ":AbstractRandom",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//src/org/perses/antlr",
        "//src/org/perses/antlr:util",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/simulator/state",
        "//src/org/perses/antlr/atn/simulator/transition",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/program",
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
        "//src/org/perses/antlr/atn/simulator/transition:printable_characters",
        "//src/org/perses/util:simple_stack_and_queue",
    ],
)
