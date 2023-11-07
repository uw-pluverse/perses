package(
    default_visibility = [
        "//antlropt/test:__subpackages__",
        "//antlrrdc/test:__subpackages__",
        "//test/org/perses:__subpackages__",
    ],
)

load("//test/org/perses:test.bzl", "golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")
load("//:perses.bzl", "kt_binary_for_genrule")

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
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//test/org/perses:test_util",
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
        "//:antlr_tool",
        "//:guava",
        "//:jgrapht",
        "//:kotlin_stdib",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//antlropt/src/org/perses/antlr/ast:ast_builder",
        "//antlropt/src/org/perses/antlr/pnf",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/util",
    ],
)

kt_binary_for_genrule(
    name = "GrammarHierarchyDumpMain",
    srcs = ["GrammarHierarchyDumpMain.kt"],
    jvm_flags = ["-ea"],
    main_class = "org.perses.antlr.GrammarHierarchyDumpMain",
    deps = [
        ":GrammarTestingUtility",
        "//:antlr_tool",
        "//:guava",
        "//:jcommander",
        "//:truth",
        "//antlropt/src/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar/c:optc_parser_facade",
        "//src/org/perses/grammar/c:parser_facade",
        "//src/org/perses/grammar/go:parser_facade",
        "//src/org/perses/grammar/scala:parser_facade",
        "//test/org/perses:test_util",
        "@com_google_protobuf//:protobuf_java",
    ],
)

kt_jvm_library(
    name = "AbstractAntlrrdcTest",
    srcs = [
        "AbstractAntlrrdcTest.kt",
    ],
    deps = [
        "//:guava",
        "//:truth",
        "//src/org/perses/util",
    ],
)

genrule(
    name = "dump_pnf_rule_hierarchy",
    srcs = [],
    outs = [
        "pnfc_rule_hierarchy.txt",
        "pnfgo_rule_hierarchy.txt",
        "pnfscala_rule_hierarchy.txt",
    ],
    cmd = "$(location :GrammarHierarchyDumpMain) " +
          " -c $(location pnfc_rule_hierarchy.txt)" +
          " -go $(location pnfgo_rule_hierarchy.txt)" +
          " -scala $(location pnfscala_rule_hierarchy.txt)",
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
