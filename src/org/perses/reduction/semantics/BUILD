load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "semantics",
    srcs = [
        "ISemanticsProvider.kt",
        "ISemanticsProviderCreator.kt",
        "ScopedDependencyGraph.kt",
        "SemanticTokenType.kt",
    ],
    deps = [
        ":layer_hierarchy",
        "//:jgrapht",
        "//src/org/perses/spartree",
        "//src/org/perses/util:mutable_int",
    ],
)

kt_jvm_library(
    name = "layer_hierarchy",
    srcs = [
        "AbstractLayer.kt",
        "LayerHierarchy.kt",
    ],
    deps = [
        "//:guava",
    ],
)
