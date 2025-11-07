load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(
    default_visibility = [
        "//visibility:public",
    ],
)

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
        "//src/org/perses/spartree",
    ],
)
