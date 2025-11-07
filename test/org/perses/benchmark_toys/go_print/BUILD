load("//:perses.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["small.go"],
    test_script = "r.sh",
)

filegroup(
    name = "go_print",
    srcs = [
        "r.sh",
        "small.go",
    ],
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_small.go",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority-dfs",
    source_file = "small.go",
    test_script = "r.sh",
)
