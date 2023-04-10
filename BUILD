package(
    default_visibility = ["//visibility:public"],
)

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "define_kt_toolchain")

alias(
    name = "antlr_tool",
    actual = "@maven//:org_antlr_antlr4",
)

alias(
    name = "antlr_runtime",
    actual = "@maven//:org_antlr_antlr4_runtime",
)

alias(
    name = "jgrapht",
    actual = "@maven//:org_jgrapht_jgrapht_core",
)

java_library(
    name = "asm",
    exports = [
        "@maven//:org_ow2_asm_asm",
        "@maven//:org_ow2_asm_asm_commons",
        "@maven//:org_ow2_asm_asm_util",
    ],
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
)

alias(
    name = "flogger",
    actual = "//src/org/perses/util:flogger_kt_exts",
)

java_library(
    name = "jackson",
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
)

java_library(
    name = "truth",
    exports = [
        "@maven//:com_google_truth_truth",
        "@maven//:com_googlecode_java_diff_utils_diffutils",
    ],
)

java_library(
    name = "gumtree",
    exports = [
        "@maven//:com_github_gumtreediff_core",
    ],
)

define_kt_toolchain(
    name = "kotlin_toolchain",
    #   Can't upgrade to 1.7 because it is still experimental which has limited JSR223 compatibility
    #   TODO(cnsun): upgrade when JSR is ready and revert back to 1.6
    api_version = "1.6",
    jvm_target = "1.8",
    language_version = "1.6",
)

exports_files(["README.md"])
