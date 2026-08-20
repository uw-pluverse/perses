load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "StatisticsListenerTest",
    srcs = ["StatisticsListenerTest.kt"],
    associates = ["//src/org/perses/reduction/event"],
    data = ["golden_statistics_listener_test.properties"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "ReducerStatisticsSummaryListenerTest",
    srcs = ["ReducerStatisticsSummaryListenerTest.kt"],
    associates = ["//src/org/perses/reduction/event"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/io:reduction_inputs",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "TestScriptExecutionListenerTest",
    srcs = ["TestScriptExecutionListenerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/reduction:abstract_reducer",
    ],
)

kt_jvm_test(
    name = "DifferentialEventsTest",
    srcs = ["DifferentialEventsTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listener:differential_events",
        "//src/org/perses/util",
    ],
)
