load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "define_kt_toolchain")

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

define_kt_toolchain(
    name = "kotlin_toolchain",
    api_version = "1.5",
    jvm_target = "1.8",
    language_version = "1.5",
)

genrule(
    name = "copy_link_jni_md_header",
    srcs = ["@bazel_tools//tools/jdk:jni_md_header-linux"],
    outs = ["jni_md.h"],
    cmd = "cp -f $< $@",
)

genrule(
    name = "copy_link_jni_header",
    srcs = ["@bazel_tools//tools/jdk:jni_header"],
    outs = ["jni.h"],
    cmd = "cp -f $< $@",
)

cc_library(
    name = "copy_jni_hdr_lib",
    hdrs = [
        ":copy_link_jni_header",
        ":copy_link_jni_md_header",
    ],
    includes = ["."],
)
