load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["small.line"],
    test_script = "r.sh",
)

name_reduce_go_print = "reduce_go_print"

output_dir_reduce_go_print = "output_dir_%s" % name_reduce_go_print

delta_debugger_profile = "delta_debugger_progress_profile.txt"

reduction_golden_test(
    name = "reduction_golden_test",
    delta_debugger_profile = delta_debugger_profile,
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_small.line",
    other_flags = {
        "--default-delta-debugger-for-kleene": "PRISTINE",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "small.line",
    test_script = "r.sh",
)

golden_test(
    name = "delta_debugger_progress_golde_test",
    golden_file = "golden_delta_debugger_progress_profile.txt",
    test_file = delta_debugger_profile,
)
