load("//test/org/perses:test.bzl", "golden_test")

java_test(
    name = "GrammarHierarchyTest",
    srcs = ["GrammarHierarchyTest.java"],
    data = [
        "//test_data/antlr_grammars",
        "//test_data/antlr_grammars:c_grammar",
    ],
    test_class = "org.perses.antlr.GrammarHierarchyTest",
    deps = [
        ":GrammarTestingUtility",
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//test/org/perses:test_util",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_guava_guava",
        "@maven//:com_google_truth_truth",
        "@maven//:org_antlr_antlr4",
    ],
)

java_library(
    name = "GrammarTestingUtility",
    srcs = ["GrammarTestingUtility.java"],
    visibility = ["//test/org/perses:__subpackages__"],
    deps = [
        "//antlropt/org/perses/antlr/ast",
        "//antlropt/org/perses/antlr/pnf",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/java:java_parser_facade",
        "//test/org/perses:test_util",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_guava_guava",
        "@maven//:com_google_truth_truth",
        "@maven//:org_antlr_antlr4",
        "@maven//:org_jgrapht_jgrapht_core",
    ],
)

java_binary(
    name = "GrammarHierarchyDumpMain",
    srcs = ["GrammarHierarchyDumpMain.java"],
    jvm_flags = ["-ea"],
    main_class = "org.perses.antlr.GrammarHierarchyDumpMain",
    deps = [
        ":GrammarTestingUtility",
        "//antlropt/org/perses/antlr/ast",
        "//src/org/perses/antlr:antlr_grammar_parser",
        "//src/org/perses/antlr:antlr_hierarchy",
        "//src/org/perses/grammar/c:c_parser_facade",
        "//src/org/perses/grammar/c:pnfc_parser_facade",
        "//src/org/perses/grammar/go:pnfgo_parser_facade",
        "//src/org/perses/grammar/scala:pnfscala_parser_facade",
        "//test/org/perses:test_util",
        "@maven//:com_beust_jcommander",
        "@maven//:com_google_flogger_flogger_system_backend",
        "@maven//:com_google_guava_guava",
        "@maven//:com_google_truth_truth",
        "@maven//:org_antlr_antlr4",
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
