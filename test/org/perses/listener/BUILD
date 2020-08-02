java_test(
    name = "StatisticsListenerTest",
    srcs = ["StatisticsListenerTest.java"],
    data = ["golden_statistics_listener_test.properties"],
    test_class = "org.perses.listener.StatisticsListenerTest",
    deps = [
        "//src/org/perses/listener:listeners",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//test/org/perses:truth",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_guava_guava",
    ],
)

java_test(
    name = "TestScriptExecutionListenerTest",
    srcs = ["TestScriptExecutionListenerTest.java"],
    test_class = "org.perses.listener.TestScriptExecutionListenerTest",
    deps = [
        "//src/org/perses/listener:listeners",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/reducer:node_based_reducer",
        "//test/org/perses:truth",
        "@maven//:com_google_guava_guava",
    ],
)
