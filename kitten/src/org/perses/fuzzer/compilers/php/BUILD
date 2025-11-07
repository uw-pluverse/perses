package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "php",
    srcs = glob(["*.kt"]),
    deps = [
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
    ],
)
