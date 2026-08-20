load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

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
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:tree_node_filter_result",
        "//src/org/perses/util:Serialization",
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
