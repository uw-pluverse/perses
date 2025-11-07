load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority-dfs",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_agressive_transformations",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress_aggressive.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--max-bfs-depth-for-regular-rule-node": "200",
        "--stop-at-first-compatible-child-for-regular-rule-node": "false",
    },
    progress_dump_file = "reduction_progress_aggressive.txt",
    reduction_algorithm = "node_priority-dfs",
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_brace_dyck_parser_facade",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress_with_brace_dyck_parser_facade.txt",
    golden_reduced_file = "golden_reduced_t_with_brace_dyck_parser_facade.c",
    other_flags = {
        "--parser-facade-class-name": "org.perses.grammar.dyck.BraceDyckParserFacade",
    },
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_brace_dyck_parenthesis_parser_facade",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress_with_brace_parenthesis_dyck_parser_facade.txt",
    golden_reduced_file = "golden_reduced_t_with_brace_parenthesis_dyck_parser_facade.c",
    other_flags = {
        "--parser-facade-class-name": "org.perses.grammar.dyck.BraceParenthesisDyckParserFacade",
    },
    source_file = "t.c",
    test_script = "r.sh",
)
