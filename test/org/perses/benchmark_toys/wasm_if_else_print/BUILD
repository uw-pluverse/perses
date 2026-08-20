load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["t.wat"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test_for_literal_replacement",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_progress_file = "golden_progress_for_literal_replacement_t.txt",
    golden_reduced_file = "golden_reduced_for_literal_replacement_t.wat",
    other_flags = {
        "--fully-deterministic-mode": "true",
        "--enable-literal-replacement-for-list-minimizer": "true",
        "--enable-literal-replacement-for-regular-rule-node": "true",
    },
    source_file = "t.wat",
    test_script = "r.sh",
)
