package(default_visibility = ["//visibility:public"])

load("@rules_proto//proto:defs.bzl", "proto_library")

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
