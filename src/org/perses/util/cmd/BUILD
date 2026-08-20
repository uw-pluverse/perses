load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "cmd",
    srcs = [
        "AbstractCommandLineFlagGroup.kt",
        "AbstractCommandOptions.kt",
        "AbstractMain.kt",
        "CommandLineProcessor.kt",
        "CommonFlagGroups.kt",
        "VerbosityFlagGroup.kt",
        "VersionFlagGroup.kt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:jackson",
        "//:jcommander",
        "//src/org/perses/util",
        "//src/org/perses/util:default_logging_configurations",
        "//version/org/perses/version",
    ],
)
