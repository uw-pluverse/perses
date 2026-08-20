load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")
load("@rules_java//java:defs.bzl", "java_binary")

kt_jvm_library(
    name = "sizetrend_lib",
    srcs = [
        "Main.kt",
        "SizeTrendCmdOptions.kt",
        "SizeTrendDataManager.kt",
        "SizeTrendWindow.kt",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//:jackson",
        "//src/org/perses/analyzer/differential",
        "//src/org/perses/util/cmd",
        "@maven//:org_jfree_jfreechart",
    ],
)

java_binary(
    name = "main",
    main_class = "org.perses.analyzer.sizetrend.Main",
    runtime_deps = [
        ":sizetrend_lib",
    ],
)
