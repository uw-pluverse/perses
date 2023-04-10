package(default_visibility = ["//antlrrdc/test:__subpackages__"])

load(
    "@io_bazel_rules_kotlin//kotlin:jvm.bzl",
    "kt_jvm_library",
    "kt_jvm_test",
)

kt_jvm_test(
    name = "E2ETest",
    size = "large",  # This is a slow test.
    srcs = [
        "E2ETest.kt",
    ],
    data = [
        "//src/org/perses/grammar/solidity/preprocessed:grammar_files",
        "//test_data/solidity_programs",
    ],
    shard_count = 7,
    deps = [
        "//:guava",
        "//:truth",
        "//antlrrdc/src/org/perses/antlr/reducer:antlr_simplifier",
        "//test/org/perses/antlr:AbstractAntlrrdcTest",
    ],
)
