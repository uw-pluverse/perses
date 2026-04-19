load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "java",
    srcs = [
        "JarFile.kt",
        "JarPackager.kt",
        "JavacWrapper.kt",
    ],
    runtime_deps = [
        "//src/org/perses/grammar:antlr_exception_strategy",
    ],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//src/org/perses/grammar:antlr_exception_strategy",
        "//src/org/perses/util",
    ],
)
