package(
    default_visibility = ["//visibility:public"],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("//:perses.bzl", "kt_binary_for_genrule")

kt_jvm_library(
    name = "SupportedLanguageDumpMain_lib",
    srcs = ["SupportedLanguageDumpMain.kt"],
    deps = [
        "//src/org/perses:abstract_reduction_main",
    ],
)

java_binary(
    name = "SupportedLanguageDumpMain",
    main_class = "org.pluverse.perses.SupportedLanguageDumpMain",
    runtime_deps = [
        ":SupportedLanguageDumpMain_lib",
    ],
)

kt_binary_for_genrule(
    name = "DownloadLinkDumpMain",
    srcs = ["DownloadLinkDumpMain.kt"],
    data = [
        "//readme_generator:build_and_use_template",
    ],
    main_class = "org.pluverse.perses.DownloadLinkDumpMain",
    deps = [
        "//src/org/perses/util/cmd",
        "//version/org/perses/version",
    ],
)

supported_languages_file = "supported_languages.segment.md"

genrule(
    name = "generate_supported_language_section",
    outs = [
        supported_languages_file,
    ],
    cmd = "$(location :SupportedLanguageDumpMain) --output $(location %s)" % supported_languages_file,
    tools = [
        ":SupportedLanguageDumpMain",
    ],
)

filegroup(
    name = "supported_languages_segment",
    srcs = [supported_languages_file],
)
