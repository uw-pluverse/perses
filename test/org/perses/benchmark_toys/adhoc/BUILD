load("//src/org/perses/grammar/adhoc:adhoc_grammar.bzl", "pnf_parser_facade_library")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load(
    "//src/org/perses:reduction.bzl",
    "DEFAULT_MAIN_REDUCTION_ALGORITHM",
    "DEFAULT_PERSES_BIN",
    "reduce",
)

sanity_test(
    name = "sanity_test",
    source_files = [
        "t.unique",
    ],
    test_script = "r.sh",
)

pnf_parser_facade_library(
    name = "parser_facade",
    java_package_name = "org.perses.test.grammar.adhoc.c",
    language_kind_yaml_file = "language_kind.yaml",
    output_jar_file_name = "parser_facade.jar",
    parser_facade_class_simple_name = "UniqueParserFacade",
    parser_file_name = "OrigC.g4",
    start_rule_name = "compilationUnit",
    token_names_of_identifiers = ["Identifier"],
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_reduced_t.unique",
    other_flags = {
        "--language-ext-jars": "$(location parser_facade.jar)",
    },
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.unique",
    test_script = "r.sh",
    deps = ["parser_facade.jar"],
)
