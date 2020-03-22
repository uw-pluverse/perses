package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "source_file",
    srcs = ["SourceFile.kt"],
    deps = [
        "//src/org/perses:language_kind",
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "program",
    srcs = glob(["*.java"]),
    exports = ["source_file"],
    deps = [
        "//src/org/perses:language_kind",
        "//src/org/perses/util",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:it_unimi_dsi_fastutil",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
