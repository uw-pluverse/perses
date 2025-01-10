package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "rust",
    srcs = glob(["*.kt"]),
    deps = [
        "//:flogger",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/util",
    ],
)
