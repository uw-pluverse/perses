load("@com_google_protobuf//bazel:java_proto_library.bzl", "java_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "rule_hierarchy_info",
    srcs = ["GrammarHierarchy.proto"],
)

java_proto_library(
    name = "grammar_hierarchy_java_proto",
    deps = [
        ":rule_hierarchy_info",
    ],
)
