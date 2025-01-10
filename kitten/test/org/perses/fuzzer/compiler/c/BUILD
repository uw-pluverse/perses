package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "CCrashDetectorTest",
    srcs = ["CCrashDetectorTest.kt"],
    data = [
        "clang_crash_output_1.txt",
        "clang_crash_output_2.txt",
        "clang_crash_output_3.txt",
        "clang_crash_output_4.txt",
        "crash_output_1.txt",
        "crash_output_2.txt",
        "crash_output_3.txt",
        "crash_output_4.txt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/c",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
