load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.py"],
    test_script = "r.sh",
)

filegroup(
    name = "python3_print",
    srcs = [
        "hello.py",
        "r.sh",
    ],
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_hello.py",
    other_flags = {
        "--code-format": "PYTHON3_FORMAT",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority-dfs",
    source_file = "hello.py",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_with_trec",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_progress_file = "golden_reduction_progress_with_trec.txt",
    golden_reduced_file = "golden_reduced_hello_with_trec.py",
    other_flags = {
        "--code-format": "PYTHON3_FORMAT",
    },
    source_file = "hello.py",
    test_script = "r.sh",
)

filegroup(
    name = "files_for_testing_TRec",
    srcs = [
        "hello_for_TRec.py",
        "r_for_TRec.sh",
    ],
)
