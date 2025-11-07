load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//visibility:public",
])

DEFAULT_DEPS = [
    "//src/org/perses/program:language_kind",
    "//src/org/perses/antlr:util",
    "//src/org/perses/antlr:antlr_hierarchy",
    "//src/org/perses/grammar:parser_facade_interface",
    "//src/org/perses/grammar/c:optc_parser_facade",
    "//src/org/perses/program",
    "//src/org/perses/spartree",
    "//src/org/perses/reduction/reducer/latra:latra_transformation_internface",
    "//src/org/perses/reduction/reducer/latra/c",
    "//src/org/perses/reduction/reducer/latra:reducer",
    "//test/org/perses:test_util",
    "//:truth",
    "//:guava",
    "//:antlr_tool",
    "//:antlr_runtime",
]

kt_jvm_test(
    name = "LatraReducerTest",
    srcs = [
        "LatraReducerTest.kt",
    ],
    deps = DEFAULT_DEPS,
)
