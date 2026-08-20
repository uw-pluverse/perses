load("//test:test.bzl", "golden_test")

package(default_visibility = ["//test:__subpackages__"])

# End-to-end golden test for directory inputs: the whole input/ directory is passed as a single
# --input <dir> and the whole deps/ directory as a single --deps <dir>. Perses expands input/ to its
# .c files and reduces them together, while deps/ is copied read-only and never reduced. The genrule
# derives each directory path from a file inside it via $(dirname $(location ...)), the same trick
# the reduce macros use for --output-dir.
genrule(
    name = "reduce",
    srcs = [
        "input/a.c",
        "input/b.c",
        "deps/dep.h",
        "r.sh",
    ],
    outs = [
        "reduced/input/a.c",
        "reduced/input/b.c",
        "progress.txt",
        "stdout.txt",
    ],
    cmd = " ".join([
        "$(location //src/org/perses:perses)",
        "--test-script $(location r.sh)",
        "--input $$(dirname $(location input/a.c))",
        "--deps $$(dirname $(location deps/dep.h))",
        "--alg node_priority",
        "--threads 1",
        "--hide-timestamps true",
        "--fully-deterministic-mode true",
        "--enable-trec false",
        "--enable-vulcan false",
        "--code-format COMPACT_ORIG_FORMAT",
        "--progress-dump-file $(location progress.txt)",
        # $(location reduced/input/a.c) -> <dir>/reduced/input/a.c; strip two components to reach the
        # --output-dir Perses writes the reduced tree into.
        "--output-dir $$(dirname $$(dirname $(location reduced/input/a.c)))",
        "&> $(location stdout.txt)",
    ]),
    tools = ["//src/org/perses"],
)

filegroup(
    name = "reduced_a",
    srcs = ["reduced/input/a.c"],
)

filegroup(
    name = "reduced_b",
    srcs = ["reduced/input/b.c"],
)

golden_test(
    name = "reduction_progress_golden_test",
    golden_file = "golden_progress.txt",
    test_file = "progress.txt",
)

golden_test(
    name = "reduced_a_golden_test",
    golden_file = "golden_reduced_a.c",
    test_file = "reduced_a",
)

golden_test(
    name = "reduced_b_golden_test",
    golden_file = "golden_reduced_b.c",
    test_file = "reduced_b",
)
