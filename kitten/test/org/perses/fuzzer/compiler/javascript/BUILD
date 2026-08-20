load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = ["//test:__subpackages__"])

kt_jvm_test(
    name = "JerryScriptCrashDetectorTest",
    srcs = ["JerryScriptCrashDetectorTest.kt"],
    data = [
        "jerry_crash_asan.txt",
        "jerry_crash_ubsan.txt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/javascript",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
