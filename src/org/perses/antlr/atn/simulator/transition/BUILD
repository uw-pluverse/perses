load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "transition",
    srcs = [
        "AbstractAtnTransitionSimulator.kt",
        "AtomTransitionSimulator.kt",
        "EpsilonTransitionSimulator.kt",
        "NotSetTransitionSimulator.kt",
        "RangeTransitionSimulator.kt",
        "SetTransitionSimulator.kt",
        "TransitionSimulatorRegistry.kt",
        "WildcardTransitionSimulator.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/antlr/atn/simulator:simulator_registry_interface",
        "//src/org/perses/antlr/atn/simulator/transition:printable_characters",
        "//src/org/perses/antlr/atn/tdtree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "printable_characters",
    srcs = ["PrintableCharacters.kt"],
    deps = [
        "//:antlr_runtime",
        "//src/org/perses/util",
    ],
)
