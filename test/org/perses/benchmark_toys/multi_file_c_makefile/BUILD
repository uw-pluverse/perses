load("//test:test.bzl", "multi_file_reduction_golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

# The Makefile is reduced with the Makefile facade; every .c with the C facade. main.c prints the
# marker the test greps for; f1.c..f4.c are dead weight the Makefile compiles in but the property does
# not need. Because the Makefile lists every source, deleting any .c up front breaks `make` -- so a
# file becomes removable only after the cross-file fixpoint strips its `SRCS += ...` line, and then
# the terminal file-deletion phase drops it. End state: only main.c + a simplified Makefile remain.
SOURCE_FILES = [
    "Makefile",
    "main.c",
    "f1.c",
    "f2.c",
    "f3.c",
    "f4.c",
]

sanity_test(
    name = "sanity_test",
    source_files = SOURCE_FILES,
    test_script = "r.sh",
)

multi_file_reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    # f1.c..f4.c are deleted, so they are not declared outputs nor golden-tested; the progress golden
    # pins the deletion behavior.
    golden_deleted_files = [
        "f1.c",
        "f2.c",
        "f3.c",
        "f4.c",
    ],
    golden_progress_file = "golden_progress.txt",
    # Parallel to the surviving files (Makefile, main.c), in SOURCE_FILES order.
    golden_reduced_files = [
        "golden_reduced_Makefile",
        "golden_reduced_main.c",
    ],
    other_flags = {
        # Makefiles are whitespace-sensitive: ORIG_FORMAT is the only format LanguageMakefile allows
        # (and C accepts it too, so it is fine for the whole mixed-language set).
        "--code-format": "ORIG_FORMAT",
        "--fully-deterministic-mode": "true",
    },
    reduction_algorithm = "node_priority",
    source_files = SOURCE_FILES,
    test_script = "r.sh",
)
