package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "event",
    srcs = glob(["*.kt"]),
    deps = [
        "//src/org/perses/reduction:reducer_name_and_desc",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/spartree",
    ],
)
