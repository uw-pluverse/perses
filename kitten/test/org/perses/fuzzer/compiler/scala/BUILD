package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "ScalaCrashDetectorTest",
    srcs = ["ScalaCrashDetectorTest.kt"],
    data = [
        "crash_output_1.txt",
        "crash_output_2.txt",
        "crash_output_3.txt",
        "noncrash_output_1.txt",
        "noncrash_output_2.txt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/scala",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
