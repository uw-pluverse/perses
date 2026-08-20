load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "ruby",
    srcs = glob(["*.kt"]),
    deps = [
        "//kitten/src/org/perses/fuzzer/compilers:compiler_configuration",
    ],
)
