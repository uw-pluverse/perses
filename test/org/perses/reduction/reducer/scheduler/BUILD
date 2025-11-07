load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")
load(
    "//test/org/perses:test.bzl",
    "cross_folder_golden_test",
)

kt_jvm_test(
    name = "ExecutionPlanYamlDefinitionTest",
    srcs = ["ExecutionPlanYamlDefinitionTest.kt"],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/reduction/scheduler",
    ],
)
