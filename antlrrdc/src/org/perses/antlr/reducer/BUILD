package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "antlr_simplifier",
    srcs = ["Main.kt"],
    deps = [
        ":command_options",
        ":grammar_reduction_driver",
        "//:jcommander",
        "//src/org/perses/util:default_logging_configurations",
        "//src/org/perses/util/cmd",
        "//version/org/perses/version",
    ],
)

java_binary(
    name = "main",
    main_class = "org.perses.antlr.reducer.Main",
    runtime_deps = [
        ":antlr_simplifier",
    ],
)

kt_jvm_library(
    name = "grammar_reduction_driver",
    srcs = [
        "GrammarReductionDriver.kt",
    ],
    deps = [
        ":language_kind",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlrrdc/src/org/perses/antlr/reducer/io",
        "//antlrrdc/src/org/perses/antlr/reducer/pass:passes",
        "//antlrrdc/src/org/perses/antlr/reducer/setup",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reduction_driver_interface",
    ],
)

kt_jvm_library(
    name = "command_options",
    srcs = ["CommandOptions.kt"],
    deps = [
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = ["LanguageAntlr.kt"],
    deps = [
        "//src/org/perses/program:language_kind",
    ],
)
