package(default_visibility = ["//test/org/perses:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "EventsTest",
    srcs = ["EventsTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//test/org/perses:test_util",
    ],
)
