load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "level_reduction_speed_analysis",
    srcs = [
        "AbstractHddPerformanceAnalysis.kt",
        "LabeledXYSeriesCollection.kt",
        "LevelReductionSpeedAnalysis.kt",
    ],
    deps = [
        "//:flogger",
        "//:guava",
        "//src/org/perses/listener:profile_event_interface",
        "@maven//:org_jfree_jfreechart",
    ],
)
