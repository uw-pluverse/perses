load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = ["//test:__subpackages__"])

kt_jvm_test(
    name = "PhpCrashDetectorTest",
    srcs = ["PhpCrashDetectorTest.kt"],
    data = [
        "php_crash.txt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
        "//kitten/src/org/perses/fuzzer/compilers/php",
        "//kitten/test/org/perses/fuzzer/compiler:CrashDetectorHelper",
    ],
)
