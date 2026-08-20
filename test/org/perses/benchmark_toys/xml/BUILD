load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.xml"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden.xml",
    other_flags = {
        "--enable-literal-replacement-for-regular-rule-node": "true",
        "--enable-literal-replacement-for-list-minimizer": "true",
    },
    reduction_algorithm = "node_priority",
    source_file = "hello.xml",
    test_script = "r.sh",
)
