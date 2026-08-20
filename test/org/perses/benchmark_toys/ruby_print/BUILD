load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.rb"],
    test_script = "r.sh",
)

filegroup(
    name = "ruby_print",
    srcs = [
        "hello.rb",
        "r.sh",
    ],
)

reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_hello.rb",
    other_flags = {
        "--enable-literal-replacement-for-list-minimizer": "true",
        "--enable-literal-replacement-for-regular-rule-node": "true",
    },
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "node_priority",
    source_file = "hello.rb",
    test_script = "r.sh",
)
