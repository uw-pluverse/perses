load("//benchmark:benchmark.bzl", "sanity_test")
load("//ppr/test/org/perses/ppr:ppr_reduction.bzl", "ppr_reduction_golden_test")
load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_library", "kt_jvm_test")

PERSES_SEED_REDUCER_BIN = "//ppr/src/org/perses/ppr/seed:main"

sanity_test(
    name = "sanity_test1",
    source_files = [
        "seed1.c",
        "variant1.c",
    ],
    test_script = "r1.sh",
)

sanity_test(
    name = "sanity_test2",
    source_files = [
        "seed2.c",
        "variant2.c",
    ],
    test_script = "r2.sh",
)

ppr_reduction_golden_test(
    name = "seed_reduction_golden_test1",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_test1.txt",
    golden_reduced_seed_file = "golden_reduced_seed1.c",
    golden_reduced_variant_file = "golden_reduced_variant1.c",
    log_file = "reduction_golden_test1.log",
    other_flags = {
        "--append-to-progress-dump-file": "true",
    },
    perses_bin = PERSES_SEED_REDUCER_BIN,
    progress_dump_file = "reduction_progress_test1.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed1.c",
    test_script = "r1.sh",
    thread_count = 1,
    variant_file = "variant1.c",
)

ppr_reduction_golden_test(
    name = "seed_reduction_golden_test2",
    enable_edit_caching = True,
    enable_query_caching = False,
    golden_progress_file = "golden_reduction_progress_test2.txt",
    golden_reduced_seed_file = "golden_reduced_seed2.c",
    golden_reduced_variant_file = "golden_reduced_variant2.c",
    log_file = "reduction_golden_test2.log",
    other_flags = {
        "--append-to-progress-dump-file": "true",
    },
    perses_bin = PERSES_SEED_REDUCER_BIN,
    progress_dump_file = "reduction_progress_test2.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    seed_file = "seed2.c",
    test_script = "r2.sh",
    thread_count = 1,
    variant_file = "variant2.c",
)

kt_jvm_test(
    name = "SeedOutputManagerFactoryTest",
    srcs = ["SeedOutputManagerFactoryTest.kt"],
    deps = [
        "//ppr/src/org/perses/ppr/diff:ppr_diff_utils",
        "//ppr/src/org/perses/ppr/seed:output_manager",
        "//ppr/src/org/perses/ppr/seed:reduction_inputs",
        "//src/org/perses/grammar/c:language_kind",
        "//src/org/perses/program",
        "//src/org/perses/program:enum_format_control",
        "//src/org/perses/program/printer",
        "//src/org/perses/util:perses_diffutil",
        "//test/org/perses:test_util",
    ],
)
