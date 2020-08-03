package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
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

java_library(
    name = "shell",
    srcs = ["Shell.java"],
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
