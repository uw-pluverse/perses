package(default_visibility = [
    "//visibility:public",
])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

kt_jvm_library(
    name = "language_model",
    srcs = [
        "AbstractLanguageModel.kt",
        "IGenerationGuide.kt",
        "NDepthTreeModel.kt",
        "NullLanguageModel.kt",
    ],
    deps = [
        "//kitten/src/org/perses/fuzzer:converter",
        "//kitten/src/org/perses/fuzzer/config:testing_configuration",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:tree_node_filter_result",
    ],
)

kt_jvm_library(
    name = "node_representation",
    srcs = [
        "NodeRepresentation.kt",
        "NodeRepresentationList.kt",
    ],
    deps = [
        "//:fastutil",
        "//:guava",
    ],
)

kt_jvm_library(
    name = "language_model_type",
    srcs = [
        "LanguageModelType.kt",
    ],
)
