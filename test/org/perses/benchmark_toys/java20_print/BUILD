load("//test:test.bzl", "reduction_golden_test", "sanity_test")

sanity_test(
    name = "sanity_test",
    source_files = ["HelloJava20.java.txt"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_HelloJava20.java.txt",
    other_flags = {
        "--lang": "java",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "HelloJava20.java.txt",
    test_script = "r.sh",
)
