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
        "//:guava",
        "//:jcommander",
        "//src/org/perses/util",
        "//src/org/perses/util:default_logging_configurations",
        "//src/org/perses/util:flogger_kt_exts",
        "//version/org/perses/version",
    ],
)
