load("//test:test.bzl", "multi_file_reduction_golden_test", "sanity_test")

package(default_visibility = ["//test:__subpackages__"])

# Unlike multi_file_three_c, the program files here live in subdirectories (src/, lib/) while the
# test script stays at the package root. This exercises the multi-file reduction path's handling of
# input/output files in directories: the reducer keeps each file at its path relative to the test
# script's directory, so the reduced files land back in src/ and lib/.
SOURCE_FILES = [
    "src/a.c",
    "lib/b.c",
    "src/main.c",
]

sanity_test(
    name = "sanity_test",
    source_files = SOURCE_FILES,
    test_script = "r.sh",
)

# golden_reduced_files is parallel to source_files: each golden holds the expected reduced content of
# the source file at the same index.
multi_file_reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    golden_reduced_files = [
        "golden_reduced_src_a.c",
        "golden_reduced_lib_b.c",
        "golden_reduced_src_main.c",
    ],
    other_flags = {
        "--fully-deterministic-mode": "true",
    },
    reduction_algorithm = "node_priority",
    source_files = SOURCE_FILES,
    test_script = "r.sh",
)
