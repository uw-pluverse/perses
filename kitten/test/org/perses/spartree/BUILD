package(default_visibility = ["//test:__subpackages__"])

load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

kt_jvm_test(
    name = "SparTreeGeneratorTest",
    srcs = ["SparTreeGeneratorTest.kt"],
    data = ["//kitten/test/fuzzer_test_data"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/fuzzer:perses_fuzzer",
        "//kitten/src/org/perses/spartree:generator",
        "//src/org/perses/grammar:facade_factory",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/c:language_kind",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "RuleGenerationInfoTest",
    srcs = ["RuleGenerationInfoTest.kt"],
    deps = [
        "//:truth",
        "//kitten/src/org/perses/spartree:generator",
    ],
)
