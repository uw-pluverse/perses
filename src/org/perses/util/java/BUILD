package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

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
        "//antlropt/src/org/perses/antlr/util:antlr_tool_wrapper",
        "//src/org/perses/grammar:antlr_exception_strategy",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/adhoc:language_kind",
        "//src/org/perses/program:source_file",
        "//src/org/perses/util",
        "//src/org/perses/util:file_name_content_pair",
    ],
)
