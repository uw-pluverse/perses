package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "source_file",
    srcs = [
        "AbstractReductionFile.kt",
        "BinaryReductionFile.kt",
        "FileWithContent.kt",
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
        "AbstractDataKind.kt",
        "LanguageKind.kt",
    ],
    deps = [
        ":enum_format_control",
        "//:guava",
        "//src/org/perses/util",
        "//src/org/perses/util/shell",
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
        "//src/org/perses/util/shell",
    ],
)

kt_jvm_library(
    name = "enum_format_control",
    srcs = ["EnumFormatControl.kt"],
)

kt_jvm_library(
    name = "program",
    srcs = [
        "AbstractLazySourceCode.kt",
        "PersesTokenFactory.kt",
        "TokenizedProgram.kt",
        "TokenizedProgramFactory.kt",
    ],
    exports = [
        "source_file",
    ],
    deps = [
        ":language_kind",
        "//:antlr_runtime",
        "//:fastutil",
        "//:flogger",
        "//:guava",
        "//src/org/perses/antlr:antlr_type_wrappers",
        "//src/org/perses/util",
        "//src/org/perses/util:fast_string_builder",
        "//src/org/perses/util:tiny_list_map",
    ],
)
