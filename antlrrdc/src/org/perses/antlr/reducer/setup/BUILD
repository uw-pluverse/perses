package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "setup",
    srcs = [
        "Setup.kt",
    ],
    deps = [
        "//antlrrdc/src/org/perses/antlr/reducer:command_options",
        "//antlrrdc/src/org/perses/antlr/reducer/codegen:templates",
        "//src/org/perses/antlr:antlr_compiler",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
        "//src/org/perses/util:auto_increment_dir",
    ],
)
