load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["small.line"],
    test_script = "r.sh",
)

name_reduce_go_print = "reduce_go_print"

output_dir_reduce_go_print = "output_dir_%s" % name_reduce_go_print

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_list_minimizer_profile = "golden_delta_debugger_progress_profile.txt",
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_small.line",
    other_flags = {
        "--default-list-minimizer-for-kleene": "PRISTINE_DDMIN",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "small.line",
    test_script = "r.sh",
)
