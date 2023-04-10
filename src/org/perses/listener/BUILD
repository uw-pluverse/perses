package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "profile_event_interface",
    srcs = ["IProfileEvent.kt"],
)

kt_jvm_library(
    name = "listeners",
    srcs = [
        "DefaultReductionListener.kt",
        "LoggingListener.kt",
        "ProgressMonitorForNodeReducer.kt",
        "ReductionProfileListener.kt",
        "StatisticsListener.kt",
        "TestScriptExecutionListener.kt",
    ],
    deps = [
        ":profile_event_interface",
        "//:flogger",
        "//:guava",
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:property_test_result",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/reduction/event",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
        "//src/org/perses/util:timeutil",
    ],
)
