package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "OrganizerDriverTest",
    srcs = ["OrganizerDriverTest.kt"],
    deps = [
        "//:flogger",
        "//:guava",
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/fuzzer/organizer:organizer_lib",
        "//kitten/test/org/perses/fuzzer:RustTestUtil",
    ],
)
