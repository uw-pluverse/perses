load("//src/org/perses:reduction.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test")

reduction_golden_test(
    name = "subtree_replacement_reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_with_subtree_replacement_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--code-format": "ORIG_FORMAT",
        "--on-demand-reducer-classes": "org.perses.reduction.reducer.vulcan.SubTreeReplacementReducer",
        "--non-deletion-iteration-limit": "20",
    },
    perses_bin = "//src/org/perses:perses",
    progress_dump_file = "progress_dump_subtree_replacement.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
)
