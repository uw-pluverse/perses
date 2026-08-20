load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")
load("@rules_java//java:defs.bzl", "java_binary")
load("//test:test.bzl", "golden_test")

DEFAULT_DEPS = [
    "//src/org/perses/program:language_kind",
    "//src/org/perses/antlr:util",
    "//src/org/perses/antlr:antlr_hierarchy",
    "//src/org/perses/grammar:parser_facade_interface",
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
    name = "SparTreeNodeFactoryTest",
    srcs = [
        "SparTreeNodeFactoryTest.kt",
    ],
    deps = DEFAULT_DEPS,
)

kt_jvm_library(
    name = "CTolerantSparTreeDumpMain",
    srcs = [
        "CTolerantSparTreeDumpMain.kt",
    ],
    deps = [
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:spar_tree_parser_utility",
        "//src/org/perses/util",
    ],
)

java_binary(
    name = "dump_tolerant_spartree_BIN",
    main_class = "org.perses.spartree.CTolerantSparTreeDumpMain",
    runtime_deps = [
        ":CTolerantSparTreeDumpMain",
    ],
)

# One tolerant-parse input program per file; each dumps to its own golden so diffs stay small and
# local. Every input is parsed with the C facade (CTolerantSparTreeDumpMain) -- including the .cpp
# case, which deliberately stresses the tolerant C parser with C++ constructs. Add a case by dropping
# the source under tolerant_spartree_inputs/, mapping <case> to its file name here, and running the
# generated golden_test_tolerant_spartree_<case>_update target.
TOLERANT_SPARTREE_CASES = {
    "valid": "valid.c",
    "missing_semicolon": "missing_semicolon.c",
    "gap_lexer": "gap_lexer.c",
    "gap_eof": "gap_eof.c",
    "deep_broken": "deep_broken.c",
    "preprocessor_conditional": "preprocessor_conditional.c",
    "preprocessor_heavy_cpp": "preprocessor_heavy.cpp",
}

[
    genrule(
        name = "dump_tolerant_spartree_%s" % case,
        srcs = ["tolerant_spartree_inputs/%s" % source],
        outs = ["%s.spartree.dump.txt" % case],
        cmd = "$(location :dump_tolerant_spartree_BIN) $(location tolerant_spartree_inputs/%s) $@" % source,
        tools = [":dump_tolerant_spartree_BIN"],
    )
    for case, source in TOLERANT_SPARTREE_CASES.items()
]

[
    golden_test(
        name = "golden_test_tolerant_spartree_%s" % case,
        golden_file = "tolerant_spartree_golden/%s.spartree.dump.golden.txt" % case,
        test_file = "%s.spartree.dump.txt" % case,
    )
    for case in TOLERANT_SPARTREE_CASES
]

kt_jvm_test(
    name = "TolerantSparTreeReconstructionTest",
    srcs = [
        "TolerantSparTreeReconstructionTest.kt",
    ],
    data = glob([
        "tolerant_spartree_inputs/*.c",
        "tolerant_spartree_inputs/*.cpp",
    ]),
    deps = DEFAULT_DEPS + [
        "//src/org/perses/grammar/c:parser_facade",
    ],
)

kt_jvm_test(
    name = "SparTreeHasSyntaxErrorsTest",
    srcs = [
        "SparTreeHasSyntaxErrorsTest.kt",
    ],
    deps = DEFAULT_DEPS + [
        "//src/org/perses/grammar/c:parser_facade",
    ],
)

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
    name = "EmptySparTreeEditTest",
    srcs = ["EmptySparTreeEditTest.kt"],
    associates = ["//src/org/perses/spartree"],
    data = [
        "//test_data/parentheses",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program/printer",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "AbstractSparTreeEditTest",
    srcs = ["AbstractSparTreeEditTest.kt"],
    associates = ["//src/org/perses/spartree"],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program/printer",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_test(
    name = "MinimalSparTreeGeneratorTest",
    srcs = ["MinimalSparTreeGeneratorTest.kt"],
    associates = [
        "//src/org/perses/spartree",
        "//src/org/perses/spartree:minimal_spartree_generator",
    ],
    deps = [
        "//:antlr_runtime",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//src/org/perses/program/printer",
        "//test/org/perses:test_util",
    ],
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
        "//src/org/perses/antlr:util",
        "//src/org/perses/grammar:parser_facade_interface",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/program",
        "//src/org/perses/program:language_kind",
        "//test/org/perses:test_util",
    ],
)
