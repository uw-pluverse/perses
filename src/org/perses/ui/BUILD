load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

kt_jvm_library(
    name = "ui",
    srcs = [
        "DashboardHtml.kt",
        "SseServer.kt",
        "WebUiListener.kt",
    ],
    deps = [
        "//:guava",
        "//:jackson",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/event",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)
