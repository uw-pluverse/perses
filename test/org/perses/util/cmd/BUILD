load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "VerbosityFlagsTest",
    srcs = ["VerbosityFlagsTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_test(
    name = "CommandOptionTest",
    srcs = ["CommandOptionTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_test(
    name = "CommandLineFlagGroupTest",
    srcs = ["CommandLineFlagGroupTest.kt"],
    deps = [
        "//:jcommander",
        "//:truth",
        "//src/org/perses/util/cmd",
    ],
)

kt_jvm_test(
    name = "CommandOptionsTest",
    srcs = ["CommandOptionsTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses:perses_command_options",
        "//src/org/perses/cmd:reduction_flags",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/util/cmd",
    ],
)
