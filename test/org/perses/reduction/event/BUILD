load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

kt_jvm_test(
    name = "EventsTest",
    srcs = ["EventsTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/reduction/reducer/token:token_slicer",
        "//src/org/perses/util",
        "//test/org/perses:test_util",
    ],
)
