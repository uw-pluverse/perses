load("//test:test.bzl", "reduction_golden_test")

exports_files([
    "r.sh",
    "t.c",
])

reduction_golden_test(
    name = "smaller_structure_replacement_reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--code-format": "COMPACT_ORIG_FORMAT",
    },
    perses_bin = "//src/org/perses:perses",
    reduction_algorithm = "sfc_smaller_structure_replacement",
    source_file = "t.c",
    test_script = "r.sh",
)
