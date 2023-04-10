package(
    default_visibility = [
        "//visibility:public",
    ],
)

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "model",
    srcs = [
        "AbstractImageTreeNode.kt",
        "ImageRegionTreeNode.kt",
        "ImageSuperpixelTreeNode.kt",
        "Pixel.kt",
        "Superpixel.kt",
    ],
    deps = [
        "//src/org/perses/cmd:reduction_flags",
        "//src/org/perses/program:source_file",
        "//src/org/perses/reduction/io:reduction_inputs_interface",
        "//src/org/perses/spartree",
        "//src/org/perses/util/cmd",
    ],
)
