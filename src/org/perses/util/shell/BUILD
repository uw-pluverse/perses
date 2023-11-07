package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "shell",
    srcs = [
        "AbstractShellDiscardingOutputPolicy.kt",
        "AbstractShellOutputStream.kt",
        "CmdOutput.kt",
        "CommonShellCommands.kt",
        "NullShellOutputStream.kt",
        "ShellCommandOnPath.kt",
        "ShellOutputLines.kt",
        "ShellOutputStream.kt",
        "Shells.kt",
    ],
    exports = [
        ":ExitCode",
    ],
    deps = [
        ":ExitCode",
        "//:flogger",
        "//:guava",
        "//src/org/perses/util",
        "@maven//:org_apache_commons_commons_exec",
    ],
)

kt_jvm_library(
    name = "ExitCode",
    srcs = ["ExitCode.kt"],
)
