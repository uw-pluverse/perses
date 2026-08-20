load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "testing_configuration",
    srcs = [
        "TestingConfiguration.kt",
    ],
    deps = [
        "//:jackson",
        "//src/org/perses/util",
        "//src/org/perses/util:Serialization",
    ],
)
