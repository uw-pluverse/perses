load("//test:test.bzl", "reduction_golden_test")

exports_files([
    "r.sh",
    "t.c",
])

# Latra and the token slicer are turned off here, and the macro already turns off Vulcan and
# T-Rec, so that the golden shows canonicalization alone: the program keeps every one of its
# tokens and only their structure changes. With the others on, the golden would show whatever
# they deleted as well, and this test would no longer be about canonicalization.
#
# The property test asks only that "if", "a" and "b" survive, and nothing asks the result to
# compile, so canonicalization is free to reach for the alternatives the C grammar spells first,
# however odd the program that results. What the golden pins is the behaviour of the reducer.
reduction_golden_test(
    name = "canonicalization_reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--code-format": "COMPACT_ORIG_FORMAT",
        "--enable-latra": "false",
        "--enable-token-slicer": "false",
    },
    perses_bin = "//src/org/perses:perses",
    reduction_algorithm = "sfc_structure_canonicalization",
    source_file = "t.c",
    test_script = "r.sh",
)
