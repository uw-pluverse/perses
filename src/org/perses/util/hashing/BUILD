load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_library",
)

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "hashing",
    srcs = [
        "EnumShaAlgorithm.kt",
        "ListToByteFunnel.kt",
        "ShaHashCode.kt",
    ],
    deps = [
        "//:guava",
    ],
)
