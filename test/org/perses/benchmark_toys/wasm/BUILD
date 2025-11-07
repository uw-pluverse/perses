load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["t.wat"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_progress_file = "golden_progress.txt",
    golden_reduced_file = "golden_reduced_t.wat",
    source_file = "t.wat",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_for_vulcan",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    enable_vulcan = True,
    golden_reduced_file = "golden_reduced_t_for_vulcan.wat",
    source_file = "t_for_vulcan.wat",
    test_script = "r_for_vulcan.sh",
)

filegroup(
    name = "files",
    srcs = [
        "r.sh",
        "t.wat",
    ],
)
