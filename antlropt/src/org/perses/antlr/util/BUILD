package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "util",
    srcs = ["Util.kt"],
    deps = [
        "//:guava",
        "//:kotlin_stdib",
    ],
)

kt_jvm_library(
    name = "antlr_tool_wrapper",
    srcs = ["AntlrToolWrapper.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//src/org/perses/util",
        "//src/org/perses/util:auto_deltable_folder",
        "//src/org/perses/util:file_name_content_pair",
    ],
)
