load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "VersionTest",
    srcs = ["VersionTest.kt"],
    deps = [
        "//:truth",
        "//version/org/perses/version",
    ],
)

kt_jvm_test(
    name = "VersionClassGeneratorTest",
    srcs = [
        "VersionClassGeneratorTest.kt",
    ],
    deps = [
        "//:truth",
        "//version/org/perses/version:version_class_generator",
    ],
)
