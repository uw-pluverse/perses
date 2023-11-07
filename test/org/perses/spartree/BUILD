load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

DEFAULT_DEPS = [
    "//src/org/perses/program:language_kind",
    "//src/org/perses/antlr:util",
    "//src/org/perses/antlr:antlr_hierarchy",
    "//src/org/perses/grammar:grammar_facade",
    "//src/org/perses/grammar/c:optc_parser_facade",
    "//src/org/perses/program",
    "//src/org/perses/program/printer",
    "//src/org/perses/spartree",
    "//test/org/perses:test_util",
    "//:truth",
    "//:guava",
    "//:antlr_tool",
    "//:antlr_runtime",
]

kt_jvm_test(
    name = "PhpSparTreeBuildTest",
    srcs = [
        "PhpSparTreeBuildTest.kt",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "NodePayloadTest",
    srcs = [
        "NodePayloadTest.kt",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "SparTreeCopierTest",
    srcs = [
        "SparTreeCopierTest.kt",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "NodeDeletionActionSetTest",
    srcs = ["NodeDeletionActionSetTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "NodeReplacementActionSetTest",
    srcs = ["NodeReplacementActionSetTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "LatraGeneralActionSetTest",
    srcs = ["LatraGeneralActionSetTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "LatraGeneralTreeEditTest",
    srcs = ["LatraGeneralTreeEditTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "JavaSparTreeBuilderTest",
    srcs = ["JavaSparTreeBuildTest.kt"],
    data = [
        "//test_data/java_helloworld",
    ],
    test_class = "org.perses.spartree.JavaSparTreeBuildTest",
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "SparTreeNodeTest",
    size = "large",
    srcs = ["SparTreeNodeTest.kt"],
    data = [
        "//test_data/misc",
    ],
    shard_count = 4,
    test_class = "org.perses.spartree.SparTreeNodeTest",
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "AbstractTreeNodeTest",
    srcs = ["AbstractTreeNodeTest.kt"],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "AbstractSparTreeNodeTest",
    srcs = ["AbstractSparTreeNodeTest.kt"],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "SparTreeSimplifierTest",
    srcs = ["SparTreeSimplifierTest.kt"],
    data = [
        "//test_data/misc",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "SparTreeTest",
    srcs = ["SparTreeTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.spartree.SparTreeTest",
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "SparTreeBuilderTest",
    srcs = ["SparTreeBuilderTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.spartree.SparTreeBuilderTest",
    deps = DEFAULT_DEPS + [
        "//src/org/perses/grammar/c:orig_parser_facade",
    ],
)

kt_jvm_test(
    name = "NodeDeletionTreeEditTest",
    srcs = ["NodeDeletionTreeEditTest.kt"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "MinimalSparTreeGeneratorTest",
    srcs = ["MinimalSparTreeGeneratorTest.kt"],
    associates = ["//src/org/perses/spartree:minimal_spartree_generator"],
    deps = DEFAULT_DEPS,
)

kt_jvm_test(
    name = "PlaceholderSparTreeNodeTest",
    srcs = ["PlaceholderSparTreeNodeTest.kt"],
    associates = ["//src/org/perses/spartree"],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:grammar_facade",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program/printer",
        "//test/org/perses:test_util",
    ],
)
