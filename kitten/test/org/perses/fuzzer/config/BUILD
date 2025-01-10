package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "TestingConfigurationTest",
    srcs = ["TestingConfigurationTest.kt"],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/c",
        "//kitten/src/org/perses/fuzzer/config:testing_configuration",
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_test(
    name = "RustcConfigurationTest",
    srcs = ["RustcConfigurationTest.kt"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/fuzzer/compilers/rust",
    ],
)
