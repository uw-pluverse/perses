load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

DEFAULT_DEPS = [
    "//src/org/perses/program:language_kind",
    "//src/org/perses/antlr:antlr_grammar_util",
    "//src/org/perses/antlr:antlr_hierarchy",
    "//src/org/perses/grammar:grammar_facade",
    "//src/org/perses/grammar/c:c_parser_facade",
    "//src/org/perses/program",
    "//src/org/perses/tree/spar",
    "//test/org/perses:test_util",
    "//test/org/perses:truth",
    "@maven//:com_google_guava_guava",
    "@maven//:org_antlr_antlr4",
    "@maven//:org_antlr_antlr4_runtime",
]

java_test(
    name = "NodeDeletionActionSetTest",
    srcs = ["NodeDeletionActionSetTest.java"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.tree.spar.NodeDeletionActionSetTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "NodeReplacementActionSetTest",
    srcs = ["NodeReplacementActionSetTest.java"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.tree.spar.NodeReplacementActionSetTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "JavaSparTreeBuilderTest",
    srcs = ["JavaSparTreeBuildTest.java"],
    data = [
        "//test_data/java_helloworld",
    ],
    test_class = "org.perses.tree.spar.JavaSparTreeBuildTest",
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
    test_class = "org.perses.tree.spar.SparTreeNodeTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "SparTreeSimplifierTest",
    srcs = ["SparTreeSimplifierTest.java"],
    data = [
        "//test_data/misc",
    ],
    test_class = "org.perses.tree.spar.SparTreeSimplifierTest",
    deps = DEFAULT_DEPS,
)

java_test(
    name = "SparTreeTest",
    srcs = ["SparTreeTest.java"],
    data = [
        "//test_data/misc",
        "//test_data/parentheses",
    ],
    test_class = "org.perses.tree.spar.SparTreeTest",
    deps = DEFAULT_DEPS,
)
