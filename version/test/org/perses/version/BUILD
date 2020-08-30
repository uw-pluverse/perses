
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "VersionTest",
    srcs = ["VersionTest.kt"],
    deps = [
        "//version/org/perses/version",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
)
