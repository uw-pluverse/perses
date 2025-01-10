package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "SlangCrashDetectorTest",
    srcs = ["SlangCrashDetectorTest.kt"],
    data = [
        "slang_ice_1.txt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
        "//kitten/src/org/perses/fuzzer/compilers/sysverilog",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
