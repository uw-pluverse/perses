load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")
load("//:perses.bzl", "kt_binary_for_genrule")
load("//test/org/perses:test.bzl", "golden_test")

package(
    default_visibility = [
        "//antlropt/test:__subpackages__",
        "//antlrrdc/test:__subpackages__",
        "//test/org/perses:__subpackages__",
    ],
)

kt_jvm_test(
    name = "ParseTreeUtilTest",
    srcs = [
        "ParseTreeUtilTest.kt",
    ],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//src/org/perses/antlr:util",
    ],
)

kt_jvm_test(
    name = "AntlrToolWrapperTest",
    srcs = ["AntlrToolWrapperTest.kt"],
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/util:antlr_tool_wrapper",
        "//src/org/perses/util",
    ],
)

kt_jvm_test(
    name = "CompilersTest",
    srcs = ["CompilersTest.kt"],
    data = [
        "//src/org/perses/grammar/solidity:grammar_files",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//antlrrdc/src/org/perses/antlr/reducer/codegen:templates",
        "//src/org/perses/antlr:antlr_compiler",
        "//src/org/perses/grammar/adhoc:language_kind",
        "//src/org/perses/grammar/adhoc:parser_facade_template",
        "//test/org/perses/antlr:AbstractAntlrrdcTest",
    ],
)

kt_jvm_test(
    name = "GrammarHierarchyTest",
    srcs = ["GrammarHierarchyTest.kt"],
    data = [
        "//test_data/antlr_grammars",
        "//test_data/antlr_grammars:c_grammar",
    ],
    deps = [
        ":GrammarTestingUtility",
        "//:antlr_tool",
        "//:guava",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/grammar/c:optc_parser_facade",
    ],
)

kt_jvm_test(
    name = "MetaTokenInfoDbTest",
    srcs = [
        "MetaTokenInfoDbTest.kt",
    ],
    associates = [
        "//src/org/perses/antlr:meta_token_info_db",
    ],
    deps = [
        "//:truth",
        "//src/org/perses/grammar/c:pnf_c_grammar",
        "//test/org/perses:test_util",
    ],
)

kt_jvm_library(
    name = "GrammarTestingUtility",
    srcs = ["GrammarTestingUtility.kt"],
    deps = [
        "//:truth",
        "//antlropt/src/org/perses/antlr/pnf",
    ],
)

kt_binary_for_genrule(
    name = "GrammarHierarchyDumpMain",
    srcs = ["GrammarHierarchyDumpMain.kt"],
    jvm_flags = ["-ea"],
    main_class = "org.perses.antlr.GrammarHierarchyDumpMain",
    deps = [
        "//:antlr_tool",
        "//:guava",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/go:parser_facade",
        "//src/org/perses/grammar/scala:parser_facade",
    ],
)

kt_jvm_test(
    name = "RuleReachabilityGraphTest",
    srcs = ["RuleReachabilityGraphTest.kt"],
    deps = [
        "//:truth",
        "//src/org/perses/grammar:parser_facade_interface",
    ],
)

kt_jvm_library(
    name = "AbstractAntlrrdcTest",
    srcs = [
        "AbstractAntlrrdcTest.kt",
    ],
    deps = [
    ],
)

genrule(
    name = "dump_pnf_rule_hierarchy",
    srcs = [],
    outs = [
        "pnfc_rule_hierarchy.txt",
        "pnfgo_rule_hierarchy.txt",
        "pnfscala_rule_hierarchy.txt",
        "pnfc_rule_graph.txt",
        "pnfgo_rule_graph.txt",
        "pnfscala_rule_graph.txt",
    ],
    cmd = "$(location :GrammarHierarchyDumpMain) " +
          " -c $(location pnfc_rule_hierarchy.txt)" +
          " -go $(location pnfgo_rule_hierarchy.txt)" +
          " -scala $(location pnfscala_rule_hierarchy.txt)" +
          " -graph-c $(location pnfc_rule_graph.txt)" +
          " -graph-go $(location pnfgo_rule_graph.txt)" +
          " -graph-scala $(location pnfscala_rule_graph.txt)",
    tools = [":GrammarHierarchyDumpMain"],
)

golden_test(
    name = "golden_test_pnfc_rule_hierarchy",
    golden_file = "golden_pnfc_rule_hierarchy.txt",
    test_file = "pnfc_rule_hierarchy.txt",
)

golden_test(
    name = "golden_test_pnfgo_rule_hierarchy",
    golden_file = "golden_pnfgo_rule_hierarchy.txt",
    test_file = "pnfgo_rule_hierarchy.txt",
)

golden_test(
    name = "golden_test_pnfscala_rule_hierarchy",
    golden_file = "golden_pnfscala_rule_hierarchy.txt",
    test_file = "pnfscala_rule_hierarchy.txt",
)

golden_test(
    name = "golden_test_pnfc_rule_graph",
    golden_file = "golden_pnfc_rule_graph.txt",
    test_file = "pnfc_rule_graph.txt",
)

golden_test(
    name = "golden_test_pnfgo_rule_graph",
    golden_file = "golden_pnfgo_rule_graph.txt",
    test_file = "pnfgo_rule_graph.txt",
)

golden_test(
    name = "golden_test_pnfscala_rule_graph",
    golden_file = "golden_pnfscala_rule_graph.txt",
    test_file = "pnfscala_rule_graph.txt",
)
