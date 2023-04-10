package(default_visibility = ["//antlrrdc:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "io",
    srcs = [
        "GrammarOutputManagerFactory.kt",
        "GrammarReductionIOManager.kt",
        "SeparateGrammarReductionInput.kt",
    ],
    deps = [
        "//antlropt/src/org/perses/antlr/ast",
        "//antlrrdc/src/org/perses/antlr/reducer/codegen:templates",
        "//src/org/perses/antlr:antlr_compiler",
        "//src/org/perses/reduction/io",
        "//src/org/perses/reduction/io:output_manager_interface",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
        "//src/org/perses/util:file_name_content_pair",
        "//src/org/perses/util/cmd",
    ],
)
