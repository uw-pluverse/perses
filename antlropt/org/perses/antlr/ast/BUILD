package(default_visibility = ["//visibility:public"])

java_library(
    name = "ast",
    srcs = glob(["*.java"]),
    deps = [
        "//antlropt/org/perses/antlr:enum_rule_type",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "@maven//:com_google_guava_guava",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_antlr_antlr4_runtime",
        "@maven//:org_antlr_antlr_runtime",
        "@maven//:org_checkerframework_checker_qual",
    ],
)
