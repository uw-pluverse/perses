load("//test:test.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["t.c"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_perses_progress.txt",
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
    },
    source_file = "t.c",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "mimir_reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_mimir_progress.txt",
    golden_reduced_file = "golden_mimir_reduced_t.c",
    other_flags = {
    },
    reduction_algorithm = "mimir",
    source_file = "t.c",
    test_script = "r.sh",
)

filegroup(
    name = "files",
    srcs = ["t.c"],
    visibility = ["//test:__subpackages__"],
)
