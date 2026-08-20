load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "WebUiListenerTest",
    srcs = ["WebUiListenerTest.kt"],
    deps = [
        "//:guava",
        "//:jackson",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/ui",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "SseServerTest",
    srcs = ["SseServerTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/ui",
    ],
)
