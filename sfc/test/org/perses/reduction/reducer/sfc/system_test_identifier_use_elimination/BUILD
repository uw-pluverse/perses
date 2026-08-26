load("//test:test.bzl", "reduction_golden_test")

exports_files([
    "r.sh",
    "t.c",
])

# Latra and the token slicer are turned off here, and the macro already turns off Vulcan and
# T-Rec, so that the golden shows this reducer alone. Vulcan matters most: its identifier
# replacement does the renaming steps of the algorithm, and with it on the golden would not say
# which of the two got rid of a use.
#
# The property test keeps "if" and "b", so every use of "a" is there to be eliminated.
reduction_golden_test(
    name = "identifier_use_elimination_reduction_golden_test",
    enable_edit_caching = False,
    enable_query_caching = False,
    golden_reduced_file = "golden_reduced_t.c",
    other_flags = {
        "--code-format": "COMPACT_ORIG_FORMAT",
        "--enable-latra": "false",
        "--enable-token-slicer": "false",
    },
    perses_bin = "//src/org/perses:perses",
    reduction_algorithm = "sfc_identifier_use_elimination",
    source_file = "t.c",
    test_script = "r.sh",
)
