load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")
load("//src/org/perses:reduction.bzl", "reduce")

sanity_test(
    name = "sanity_test",
    source_files = ["t.cpp"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_t.cpp",
    log_file = "reduction_golden_test.log",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "t.cpp",
    test_script = "r.sh",
)

filegroup(
    name = "files",
    srcs = ["t.cpp"],
    visibility = ["//test:__subpackages__"],
)
