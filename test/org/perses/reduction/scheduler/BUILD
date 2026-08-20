load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "ReducerSchedulerTest",
    srcs = ["ReducerSchedulerTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/program",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:stats_of_files_under_reduction",
        "//src/org/perses/reduction/scheduler",
        "//src/org/perses/util/hashing",
    ],
)
