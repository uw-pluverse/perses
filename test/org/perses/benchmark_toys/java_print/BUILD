load("//test:test.bzl", "golden_test", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["Hello.java"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_Hello.java.txt",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "Hello.java",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_vulcan_and_auto_query_caching",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_vulcan = True,
    extra_output_files = [
        "updated_global_cache.csv",
    ],
    golden_progress_file = "golden_reduction_progress_with_vulcan_and_auto_query_caching.txt",
    golden_reduced_file = "golden_reduced_Hello_with_vulcan_and_auto_query_caching.java.txt",
    other_flags = {
        "--global-caching": "true",
        "--global-cache-file": "$(location golden_global_cache.csv)",
        "--path-to-save-updated-global-cache": "$(location updated_global_cache.csv)",
    },
    progress_dump_file = "reduction_progress_with_vulcan_and_auto_query_caching.txt",
    reduction_algorithm = "node_priority",
    source_file = "Hello.java",
    test_script = "r.sh",
    deps = [
        "golden_global_cache.csv",
    ],
)

golden_test(
    name = "golden_test_global_cache",
    golden_file = "golden_global_cache.csv",
    test_file = "updated_global_cache.csv",
)
