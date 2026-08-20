load("//test:test.bzl", "multi_file_reduction_golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

SOURCE_FILES = [
    "prog.c",
    "App.java",
]

sanity_test(
    name = "sanity_test",
    source_files = SOURCE_FILES,
    test_script = "r.sh",
)

# Reduces a C file and a Java file together (one --input-file per file) against a single
# interestingness test, exercising the per-file parser-facade selection of the multi-file reduction
# path: prog.c is parsed/reduced with the C facade and App.java with the Java facade. Each reduced
# file is golden-tested separately.
multi_file_reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_progress_file = "golden_progress.txt",
    golden_reduced_files = [
        "golden_reduced_prog.c",
        "golden_reduced_App.java.txt",
    ],
    other_flags = {
        "--fully-deterministic-mode": "true",
    },
    reduction_algorithm = "node_priority",
    source_files = SOURCE_FILES,
    test_script = "r.sh",
)
