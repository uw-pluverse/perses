load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "rust",
    srcs = [
        "RustTransformationList.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/grammar/rust:orig_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
    ],
)
