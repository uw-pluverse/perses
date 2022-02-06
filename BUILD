package(
    default_visibility = ["//visibility:public"],
)

###################################################################################################
#
# The following is copied from
#        https://github.com/bazelbuild/buildtools/tree/master/buildifier
#
###################################################################################################
load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "define_kt_toolchain")

buildifier(
    name = "buildifier",
)

alias(
    name = "antlr_tool",
    actual = "@maven//:org_antlr_antlr4",
)

alias(
    name = "antlr_runtime",
    actual = "@maven//:org_antlr_antlr4_runtime",
)

alias(
    name = "asm",
    actual = "@maven//:org_ow2_asm_asm_all",
)

alias(
    name = "kotlin_stdib",
    actual = "@maven//:org_jetbrains_kotlin_kotlin_stdlib_jdk8",
)

alias(
    name = "fastutil",
    actual = "@maven//:it_unimi_dsi_fastutil",
)

java_binary(
    name = "ktlint",
    main_class = "com.pinterest.ktlint.Main",
    runtime_deps = [
        "@maven//:com_pinterest_ktlint",
    ],
)

java_binary(
    name = "google_java_format",
    main_class = "com.google.googlejavaformat.java.Main",
    runtime_deps = [
        "@maven//:com_google_googlejavaformat_google_java_format",
    ],
)

java_binary(
    name = "detekt",
    main_class = "io.gitlab.arturbosch.detekt.cli.Main",
    runtime_deps = [
        "@maven//:io_gitlab_arturbosch_detekt_detekt_cli",
    ],
)

alias(
    name = "guava",
    actual = "@maven//:com_google_guava_guava",
    visibility = ["//visibility:public"],
)

java_library(
    name = "flogger",
    visibility = ["//visibility:public"],
    exports = [
        "//src/org/perses/util:flogger_kt_exts",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_flogger_flogger_system_backend",
    ],
)

java_library(
    name = "jackson",
    visibility = ["//visibility:public"],
    exports = [
        "@maven//:com_fasterxml_jackson_core_jackson_annotations",
        "@maven//:com_fasterxml_jackson_core_jackson_core",
        "@maven//:com_fasterxml_jackson_core_jackson_databind",
        "@maven//:com_fasterxml_jackson_dataformat_jackson_dataformat_yaml",
        "@maven//:com_fasterxml_jackson_datatype_jackson_datatype_guava",
        "@maven//:com_fasterxml_jackson_module_jackson_module_kotlin",
    ],
)

alias(
    name = "jcommander",
    actual = "@maven//:com_beust_jcommander",
    visibility = ["//visibility:public"],
)

java_library(
    name = "truth",
    visibility = ["//visibility:public"],
    exports = [
        "@maven//:com_google_truth_truth",
        "@maven//:com_googlecode_java_diff_utils_diffutils",
    ],
)

define_kt_toolchain(
    name = "kotlin_toolchain",
    api_version = "1.5",
    jvm_target = "1.8",
    language_version = "1.5",
)
