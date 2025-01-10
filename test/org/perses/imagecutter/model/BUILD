load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//fuzzer/org/perses:__subpackages__",
    "//fuzzer_test/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_test(
    name = "PixelTest",
    srcs = [
        "PixelTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/imagecutter/model",
    ],
)
