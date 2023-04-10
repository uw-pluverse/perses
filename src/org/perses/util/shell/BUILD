package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "shell",
    srcs = [
        "AbstractShell.kt",
        "AbstractShellOutputStream.kt",
        "CmdOutput.kt",
        "NullShellOutputStream.kt",
        "ShellBasedOnApacheExec.kt",
        "ShellCommandOnPath.kt",
        "ShellOutputLines.kt",
        "ShellOutputStream.kt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//src/org/perses/util",
        "@maven//:org_apache_commons_commons_exec",
    ],
)
