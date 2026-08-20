load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "reducer",
    srcs = [
        "CoarseGritLatraReducerAnnotation.kt",
        "DefaultLatraReducer.kt",
        "FineGritLatraReducerAnnotation.kt",
    ],
    deps = [
        ":transformation_registry",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//latra/src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//latra/src/org/perses/reduction/reducer/latra/c",
        "//latra/src/org/perses/reduction/reducer/latra/rust",
        "//latra/src/org/perses/reduction/reducer/latra/smt",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "transformation_registry",
    srcs = [
        "TransformationRegistry.kt",
    ],
    deps = [
        "//latra/src/org/perses/reduction/reducer/latra/c",
        "//latra/src/org/perses/reduction/reducer/latra/rust",
        "//latra/src/org/perses/reduction/reducer/latra/smt",
        "//latra/src/org/perses/reduction/reducer/latra/wat",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/grammar/smtlibv2:language_kind",
    ],
)

kt_jvm_library(
    name = "exceptions",
    srcs = [
        "LatraEmptyHoleBindingException.kt",
        "LatraException.kt",
    ],
)

kt_jvm_library(
    name = "SparTreeHoleMatchPayload",
    srcs = [
        "SparTreeHoleMatchPayload.kt",
    ],
    deps = [
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "latra_transformation_internface",
    srcs = [
        "AbstractLatraRewriterBuilder.kt",
        "AbstractLatraTransformationList.kt",
        "FullFunctionalLatraRewriterBuilder.kt",
        "IProgramPrinter.kt",
        "LatraArguments.kt",
        "LatraRewriterBuilderForSimpleFromToPattern.kt",
        "LatraTransformation.kt",
        "SparTreeHoleMatch.kt",
        "TransformationUtility.kt",
    ],
    deps = [
        ":SparTreeHoleMatchPayload",
        ":exceptions",
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:arrow_kt",
        "//latra/src/org/perses/reduction/reducer/latra/language",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/smtlibv2:language_kind",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//src/org/perses/listminimizer:ListMinimizerFactory",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//src/org/perses/spartree",
    ],
)
