load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "c",
    srcs = [
        "CTransformationList.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:orig_parser_facade",
        "//src/org/perses/grammar/smtlibv2:language_kind",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/spartree",
    ],
)
