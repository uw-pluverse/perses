load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("@rules_java//java:defs.bzl", "java_binary")

kt_jvm_library(
    name = "differential",
    srcs = [
        "DifferentialAnalyzerCmdOptions.kt",
        "EventDiffStatistics.kt",
        "EventDiffTreeModelBuilder.kt",
        "EventDiffWindow.kt",
        "FileSelectionDialog.kt",
        "Main.kt",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//:jackson",
        "//src/org/perses/listener:differential_events",
        "//src/org/perses/util/cmd",
        "@maven//:org_jfree_jfreechart",
    ],
)

java_binary(
    name = "Main",
    main_class = "org.perses.analyzer.differential.Main",
    runtime_deps = [
        ":differential",
    ],
)
