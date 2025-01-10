package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "javascript",
    srcs = glob(["*.kt"]),
    deps = [
        "//:flogger",
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
        "//src/org/perses/grammar/javascript:language_kind",
    ],
)
