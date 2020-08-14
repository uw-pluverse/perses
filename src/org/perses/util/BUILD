package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

java_library(
    name = "util",
    srcs = glob(
        ["*.java"],
        exclude = [
            "AntlrParseTreePdfier.java",
            "Shell.java",
        ],
    ),
    deps = [
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:it_unimi_dsi_fastutil",
    ],
)

sh_binary(
    name = "migrate_from_maven_jar",
    srcs = [":migrate_from_maven_jar.sh"],
)

kt_jvm_library(
    name = "shell",
    srcs = [
        "Shell.kt",
        "ShellOutputLines.kt",
        "ShellOutputStream.kt",
    ],
    deps = [
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_apache_commons_commons_exec",
    ],
)

kt_jvm_library(
    name = "percentage",
    srcs = ["Fraction.kt"],
)

kt_jvm_library(
    name = "double_linked_list",
    srcs = ["DoubleLinkedList.kt"],
)

kt_jvm_library(
    name = "default_logging_configurations",
    srcs = ["DefaultLoggingConfigurations.kt"],
)

kt_jvm_library(
    name = "performance_monitor",
    srcs = ["PerformanceMonitor.kt"],
    deps = [
        "@maven//:com_google_guava_guava",
        "@maven//:it_unimi_dsi_fastutil",
    ],
)

kt_jvm_library(
    name = "timeutil",
    srcs = ["TimeUtil.kt"],
    deps = [
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "auto_deltable_folder",
    srcs = ["AutoDeletableFolder.kt"],
    deps = [
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "command_line_flags",
    srcs = [
        "AbstractCommandOptions.kt",
        "ICommandLineFlags.kt",
    ],
    deps = [
        "@maven//:com_beust_jcommander",
    ],
)
