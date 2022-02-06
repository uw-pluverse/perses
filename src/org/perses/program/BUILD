package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "source_file",
    srcs = [
        "AbstractSourceFile.kt",
        "ScriptFile.kt",
        "SourceFile.kt",
    ],
    deps = [
        ":language_kind",
        "//:guava",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "language_kind",
    srcs = [
        "LanguageKind.kt",
    ],
    deps = [
        ":enum_format_control",
        "//:guava",
        "//src/org/perses/util:perses_kt_exts",
        "//src/org/perses/util:shell",
    ],
)

kt_jvm_library(
    name = "serializable_language_kind",
    srcs = [
        "SerializableLanguageKind.kt",
    ],
    deps = [
        ":enum_format_control",
        ":language_kind",
        "//:guava",
        "//:jackson",
        "//src/org/perses/util:YamlUtil",
        "//src/org/perses/util:shell",
    ],
)

java_library(
    name = "enum_format_control",
    srcs = ["EnumFormatControl.java"],
)

kt_jvm_library(
    name = "program",
    srcs = [
        "AbstractLazySourceCode.kt",
        "AbstractTokenizedProgramPrinter.kt",
        "PersesTokenFactory.kt",
        "TokenizedProgram.kt",
        "TokenizedProgramFactory.kt",
    ],
    exports = [
        "source_file",
    ],
    deps = [
        ":language_kind",
        "//:flogger",
        "//:guava",
        "//src/org/perses/util:fast_string_builder",
        "//src/org/perses/util:perses_kt_exts",
        "//src/org/perses/util:tiny_list_map",
        "@maven//:it_unimi_dsi_fastutil",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
