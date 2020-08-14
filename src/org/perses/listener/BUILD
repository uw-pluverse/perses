package(default_visibility = [
    "//src/org/perses:__subpackages__",
    "//test/org/perses:__subpackages__",
])

java_library(
    name = "profile_event_interface",
    srcs = ["IProfileEvent.java"],
)

java_library(
    name = "listeners",
    srcs = [
        "DefaultReductionListener.java",
        "LoggingListener.java",
        "ProgressMonitorForNodeReducer.java",
        "ReductionProfileListener.java",
        "StatisticsListener.java",
        "TestScriptExecutionListener.java",
    ],
    deps = [
        ":profile_event_interface",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:test_script",
        "//src/org/perses/tree/spar",
        "//src/org/perses/util",
        "//src/org/perses/util:timeutil",
        "@maven//:com_google_flogger_flogger",
        "@maven//:com_google_guava_guava",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
