load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "language",
    srcs = [
        "AbstractLatraAst.kt",
        "AbstractLatraPattern.kt",
        "AbstractPatternClause.kt",
        "AbstractPatternElement.kt",
        "AbstractPatternElementBindings.kt",
        "FromClause.kt",
        "LatraTransformationDefinition.kt",
        "PatternElementParser.kt",
        "SuchAsClause.kt",
        "ToClause.kt",
        "WhereClause.kt",
        "WhereCondition.kt",
    ],
    deps = [
        "//:antlr_runtime",
        "//:guava",
        "//latra/src/org/perses/reduction/reducer/latra:exceptions",
        "//latra/src/org/perses/reduction/reducer/latra/language/io",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/spartree",
    ],
)
