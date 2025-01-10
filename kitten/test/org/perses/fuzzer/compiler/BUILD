package(default_visibility = ["//kitten/test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "CrashSignatureTest",
    srcs = ["CrashSignatureTest.kt"],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
    ],
)

kt_jvm_library(
    name = "CrashDetectorHelper",
    srcs = [
        "CrashDetectorHelper.kt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
    ],
)
