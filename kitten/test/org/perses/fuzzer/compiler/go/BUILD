package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "GoCrashDetectorTest",
    srcs = ["GoCrashDetectorTest.kt"],
    data = [
        "go-47723-bug.txt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/c",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
