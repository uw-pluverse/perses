java_test(
    name = "StatisticsListenerTest",
    srcs = ["StatisticsListenerTest.java"],
    data = ["golden_statistics_listener_test.properties"],
    test_class = "org.perses.listener.StatisticsListenerTest",
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/event",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//src/org/perses/spartree",
    ],
)

java_test(
    name = "TestScriptExecutionListenerTest",
    srcs = ["TestScriptExecutionListenerTest.java"],
    test_class = "org.perses.listener.TestScriptExecutionListenerTest",
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/listener:listeners",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/reducer:node_based_reducer",
    ],
)
