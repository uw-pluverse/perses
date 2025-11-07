load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.yaml"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden.yaml",
    other_flags = {
        "--code-format": "YAML_FORMAT",
    },
    reduction_algorithm = "node_priority-dfs",
    source_file = "hello.yaml",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_for_TREc",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_progress_file = "golden_progress.txt",
    golden_reduced_file = "golden.yaml",
    other_flags = {
        "--code-format": "YAML_FORMAT",
    },
    reduction_algorithm = "node_priority-dfs",
    source_file = "hello.yaml",
    test_script = "r.sh",
)
