package(default_visibility = [
    "//visibility:public"
])

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "source_file",
    srcs = [
        "AbstractSourceFile.kt",
        "ScriptFile.kt",
        "SourceFile.kt",
    ],
    deps = [
        ":language_kind",
        "@maven//:com_google_guava_guava",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = [
        "LanguageKind.kt",
    ],
    deps = [
        ":enum_format_control",
        "@maven//:com_google_guava_guava",
    ],
)

java_library(
    name = "enum_format_control",
    srcs = ["EnumFormatControl.java"],
)

java_library(
    name = "program",
    srcs = [
        "AbstractLazySourceCode.java",
        "PersesToken.java",
        "PersesTokenFactory.java",
        "TokenizedProgram.java",
        "TokenizedProgramFactory.java",
    ],
    exports = [
        "enum_format_control",
        "source_file",
    ],
    deps = [
        ":enum_format_control",
        ":language_kind",
        "//src/org/perses/util",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:it_unimi_dsi_fastutil",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
