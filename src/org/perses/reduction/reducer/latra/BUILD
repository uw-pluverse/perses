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
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction/reducer/latra:latra_transformation_internface",
        "//src/org/perses/reduction/reducer/latra/c",
        "//src/org/perses/reduction/reducer/latra/rust",
        "//src/org/perses/reduction/reducer/latra/smt",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "transformation_registry",
    srcs = [
        "TransformationRegistry.kt",
    ],
    deps = [
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/grammar/rust:language_kind",
        "//src/org/perses/grammar/smtlibv2:language_kind",
        "//src/org/perses/reduction/reducer/latra/c",
        "//src/org/perses/reduction/reducer/latra/rust",
        "//src/org/perses/reduction/reducer/latra/smt",
        "//src/org/perses/reduction/reducer/latra/wat",
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
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/smtlibv2:language_kind",
        "//src/org/perses/grammar/smtlibv2:parser_facade",
        "//src/org/perses/listminimizer:ListMinimizerFactory",
        "//src/org/perses/listminimizer:enum_list_input_minimizer_type",
        "//src/org/perses/listminimizer:interfaces",
        "//src/org/perses/program",
        "//src/org/perses/program/printer",
        "//src/org/perses/reduction/reducer/latra/language",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "rewriter_builder",
    testonly = True,
    srcs = [
        "FullFunctionalLatraRewriterBuilder.kt",
        "LatraRewriterBuilderForSimpleFromToPattern.kt",
    ],
    deps = [
        ":latra_transformation_internface",
    ],
)
