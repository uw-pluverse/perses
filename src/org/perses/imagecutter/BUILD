package(
    default_visibility = [
        "//visibility:public",
    ],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

java_binary(
    name = "perses_image_reducer",
    srcs = [
        "Main.java",
    ],
    deps = [],
)

kt_jvm_library(
    name = "imagecutter",
    srcs = [
        "CommandOptions.kt",
        "ImageDataKind.kt",
        "ImageReductionInput.kt",
    ],
    deps = [
        "//src/org/perses/cmd:reduction_flags",
        "//src/org/perses/program:source_file",
        "//src/org/perses/reduction/io:reduction_inputs_interface",
        "//src/org/perses/util/cmd",
    ],
)
