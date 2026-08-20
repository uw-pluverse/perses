load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = ["//test:__subpackages__"])

kt_jvm_test(
    name = "GoCrashDetectorTest",
    srcs = ["GoCrashDetectorTest.kt"],
    data = [
        "go-47723-bug.txt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/c",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
