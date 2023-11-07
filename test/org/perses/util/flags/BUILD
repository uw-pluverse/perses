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
