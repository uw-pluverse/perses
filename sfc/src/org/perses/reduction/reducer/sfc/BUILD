load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "rule_alternative_template",
    srcs = [
        "Quantifier.kt",
        "RuleAlternativeTemplate.kt",
        "RuleAlternativeTemplateBuilder.kt",
        "TemplateElement.kt",
    ],
    deps = [
        "//:guava",
        "//antlropt/src/org/perses/antlr:enum_rule_type",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:meta_token_info_db",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "structure_reuse_finder",
    srcs = [
        "StructureReuseFinder.kt",
    ],
    deps = [
        "//:guava",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "template_filling",
    srcs = [
        "FilledHole.kt",
        "TemplateFilling.kt",
    ],
    deps = [
        ":rule_alternative_template",
        "//:guava",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "template_hole_filler",
    srcs = [
        "TemplateHoleFiller.kt",
    ],
    deps = [
        ":rule_alternative_template",
        ":structure_reuse_finder",
        ":template_filling",
        "//:guava",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "candidate_subtree_builder",
    srcs = [
        "CandidateSubtreeBuilder.kt",
    ],
    deps = [
        ":rule_alternative_template",
        ":template_filling",
        "//:guava",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
    ],
)

kt_jvm_library(
    name = "structure_form_converter",
    srcs = [
        "StructureFormConverter.kt",
    ],
    deps = [
        ":candidate_subtree_builder",
        ":rule_alternative_template",
        ":template_filling",
        ":template_hole_filler",
        "//:guava",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/program",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "smaller_structure_replacement_reducer",
    srcs = [
        "AbstractStructureFormConversionReducer.kt",
        "IdentifierUseEliminationReducer.kt",
        "SmallerStructureReplacementReducer.kt",
        "StructureCanonicalizationReducer.kt",
    ],
    deps = [
        ":rule_alternative_path",
        ":structure_form_converter",
        ":structure_reuse_finder",
        "//:guava",
        "//src/org/perses/reduction:abstract_reducer",
        "//src/org/perses/reduction:reducer_context_interface",
        "//src/org/perses/spartree",
        "//src/org/perses/util",
    ],
)

kt_jvm_library(
    name = "rule_alternative_path",
    srcs = [
        "RuleAlternativePath.kt",
    ],
    deps = [
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/util",
    ],
)
