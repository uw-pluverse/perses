load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "ast",
    srcs = [
        "AbstractASTSimulator.kt",
        "AltBlockAstSimulator.kt",
        "OptionalAstSimulator.kt",
        "PlusAstSimulator.kt",
        "SequenceASTSimulator.kt",
        "StarAstSimulator.kt",
        "TransitionASTSimulator.kt",
    ],
    deps = [
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr/atn/nfa",
        "//src/org/perses/antlr/atn/simulator/transition",
    ],
)
