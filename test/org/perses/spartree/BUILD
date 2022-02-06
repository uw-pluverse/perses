load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

DEFAULT_DEPS = [
    "//src/org/perses/program:language_kind",
    "//src/org/perses/antlr:antlr_grammar_util",
    "//src/org/perses/antlr:antlr_hierarchy",
    "//src/org/perses/grammar:grammar_facade",
    "//src/org/perses/grammar/c:optc_parser_facade",
    "//src/org/perses/program",
    "//src/org/perses/program/printer",
    "//src/org/perses/spartree",
    "//test/org/perses:test_util",
    "//:truth",
    "//:guava",
    "@maven//:org_antlr_antlr4",
    "@maven//:org_antlr_antlr4_runtime",
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

java_test(
    name = "NodeDeletionActionSetTest",
    srcs = ["NodeDeletionActionSetTest.java"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.spartree.NodeDeletionActionSetTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "NodeReplacementActionSetTest",
    srcs = ["NodeReplacementActionSetTest.java"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.spartree.NodeReplacementActionSetTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "JavaSparTreeBuilderTest",
    srcs = ["JavaSparTreeBuildTest.java"],
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
