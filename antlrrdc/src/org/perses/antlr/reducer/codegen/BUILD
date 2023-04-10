package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "templates",
    srcs = [
        "GrammarMainStubFactory.kt",
        "GrammarMainStubTemplate.kt",
        "ReductionScriptTemplate.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/antlr:abstract_grammar_stub",
        "//src/org/perses/program:source_file",
        "//src/org/perses/util",
        "//src/org/perses/util:AbstractBashScriptGenerator",
    ],
)
