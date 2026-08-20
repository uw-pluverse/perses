load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = ["//test:__subpackages__"])

kt_jvm_test(
    name = "JavacCrashDetectorTest",
    srcs = ["JavacCrashDetectorTest.kt"],
    data = [
        "bug1.txt",
        "bug2.txt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
        "//kitten/src/org/perses/fuzzer/compilers/javac:java",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
