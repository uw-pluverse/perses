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
    golden_reduced_file = "golden_reduced_t.c",
    source_file = "t.c",
    test_script = "r.sh",
)

filegroup(
    name = "files",
    srcs = ["t.c"],
    visibility = ["//test:__subpackages__"],
)
