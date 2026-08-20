load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "scheduler",
    srcs = [
        "AbstractSchedulerEvent.kt",
        "ExecutionPlanYamlDefinition.kt",
        "ReducerExecutionPlan.kt",
        "ReducerScheduler.kt",
    ],
    deps = [
        "//:guava",
        "//:jackson",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:stats_of_files_under_reduction",
        "//src/org/perses/util",
        "//src/org/perses/util:Serialization",
    ],
)
