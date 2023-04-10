package(default_visibility = ["//visibility:public"])

load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "spartree_proto",
    srcs = ["SparTreeMessage.proto"],
)

java_proto_library(
    name = "spartree_java_proto",
    deps = [
        ":spartree_proto",
    ],
)
