package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "JerryScriptCrashDetectorTest",
    srcs = ["JerryScriptCrashDetectorTest.kt"],
    data = [
        "jerry_crash_asan.txt",
        "jerry_crash_ubsan.txt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/javascript",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
