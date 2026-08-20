load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "topformflat_chunker",
    srcs = ["TopFormFlatChunker.kt"],
    deps = [
        "//:guava",
        "//src/org/perses/spartree",
        "//src/org/perses/util:immutable_list_builder_ext",
    ],
)

kt_jvm_library(
    name = "line_reducer",
    srcs = ["TopFormFlatReducer.kt"],
    deps = [
        ":topformflat_chunker",
        "//:guava",
        "//src/org/perses/grammar/dyck:AbstractDyckParserFacade",
        "//src/org/perses/grammar/flattokenlist:parser_facade",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)
