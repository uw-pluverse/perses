load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = ["//test:__subpackages__"])

kt_jvm_test(
    name = "SparTreeGeneratorTest",
    srcs = ["SparTreeGeneratorTest.kt"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/spartree:generator",
        "//kitten/test/org/perses/fuzzer:tiny_grammar_facade",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:language_kind",
    ],
)

kt_jvm_test(
    name = "RuleGenerationInfoTest",
    srcs = ["RuleGenerationInfoTest.kt"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/spartree:generator",
        "//src/org/perses/grammar:facade_factory",
    ],
)
