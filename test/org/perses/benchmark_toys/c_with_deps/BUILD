load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = [
        "t.c",
        "dep1.c",
        "dep2.c",
    ],
    test_script = "r.sh",
)

LOG_FILE = "reduction_golden_test.log"

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_file = "golden_reduced_t.c",
    log_file = LOG_FILE,
    other_flags = {
        "--deps": "$(location dep1.c),$(location dep2.c)",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.c",
    test_script = "r.sh",
    deps = [
        "dep1.c",
        "dep2.c",
    ],
)
