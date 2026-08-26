load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_library(
    name = "sfc_test_utility",
    srcs = [
        "AbstractSfcTestWithGeneratedFacade.kt",
        "SfcTestUtility.kt",
    ],
    deps = [
        "//:guava",
        "//sfc/src/org/perses/reduction/reducer/sfc:rule_alternative_template",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
        "@maven//:junit_junit",
    ],
)

kt_jvm_test(
    name = "RuleAlternativeTemplateBuilderTest",
    srcs = ["RuleAlternativeTemplateBuilderTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:rule_alternative_template",
    ],
    deps = [
        ":sfc_test_utility",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:parser_facade",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "StructureReuseFinderTest",
    srcs = ["StructureReuseFinderTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:structure_reuse_finder",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "TemplateHoleFillerTest",
    srcs = ["TemplateHoleFillerTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:template_hole_filler",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//sfc/src/org/perses/reduction/reducer/sfc:rule_alternative_template",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "CandidateSubtreeBuilderTest",
    srcs = ["CandidateSubtreeBuilderTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:candidate_subtree_builder",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//sfc/src/org/perses/reduction/reducer/sfc:rule_alternative_template",
        "//sfc/src/org/perses/reduction/reducer/sfc:template_filling",
        "//sfc/src/org/perses/reduction/reducer/sfc:template_hole_filler",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "StructureFormConverterTest",
    srcs = ["StructureFormConverterTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:structure_form_converter",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "StructureFormConverterCTest",
    srcs = ["StructureFormConverterCTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:structure_form_converter",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "SmallerStructureReplacementReducerTest",
    srcs = ["SmallerStructureReplacementReducerTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:smaller_structure_replacement_reducer",
    ],
    data = [
        "//sfc/test/org/perses/reduction/reducer/sfc/system_test_smaller_structure:r.sh",
        "//sfc/test/org/perses/reduction/reducer/sfc/system_test_smaller_structure:t.c",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/spartree",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "StructureCanonicalizationReducerTest",
    srcs = ["StructureCanonicalizationReducerTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:smaller_structure_replacement_reducer",
    ],
    data = [
        "//sfc/test/org/perses/reduction/reducer/sfc/system_test_smaller_structure:r.sh",
        "//sfc/test/org/perses/reduction/reducer/sfc/system_test_smaller_structure:t.c",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//sfc/src/org/perses/reduction/reducer/sfc:rule_alternative_path",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/spartree",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "RuleAlternativePathTest",
    srcs = ["RuleAlternativePathTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:rule_alternative_path",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar:parser_facade_interface",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "IdentifierUseEliminationReducerTest",
    srcs = ["IdentifierUseEliminationReducerTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:smaller_structure_replacement_reducer",
    ],
    data = [
        "//sfc/test/org/perses/reduction/reducer/sfc/system_test_identifier_use_elimination:r.sh",
        "//sfc/test/org/perses/reduction/reducer/sfc/system_test_identifier_use_elimination:t.c",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//src/org/perses/reduction:reducer_factory",
        "//src/org/perses/spartree",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)

kt_jvm_test(
    name = "PaperExampleSimplificationsTest",
    srcs = ["PaperExampleSimplificationsTest.kt"],
    associates = [
        "//sfc/src/org/perses/reduction/reducer/sfc:structure_form_converter",
    ],
    deps = [
        ":sfc_test_utility",
        "//:truth",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/spartree",
        "//test/org/perses:test_util",
    ],
)
