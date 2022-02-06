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
        "//src/org/perses/util:default_logging_configurations",
        "//version/org/perses/version",
        "@maven//:com_beust_jcommander",
    ],
)
