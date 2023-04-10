package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "cmd",
    srcs = [
        "AbstractCommandOptions.kt",
        "AbstractMain.kt",
        "CommonCmdOptionGroupOrder.kt",
        "ICommandLineFlags.kt",
        "VerbosityFlags.kt",
        "VersionFlags.kt",
    ],
    deps = [
        "//:jcommander",
        "//src/org/perses/util:default_logging_configurations",
        "//version/org/perses/version",
    ],
)
