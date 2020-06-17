package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//src/org/perses:reduction.bzl", "reduce")
load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

sanity_test(
    name = "sanity_test",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

filegroup(
    name = "scala_print",
    srcs = [
        "Hello.sc",
        "r.sh",
    ],
)

reduce(
    name = "reduce_scala_print",
    enable_edit_caching = True,
    enable_query_caching = True,
    progress_dump_file = "progress_dump.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    result_file = "Hello_reduced.scala",
    source_file = "Hello.sc",
    statistics_file = "statistics.txt",
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    golden_progress_file = "golden_reduction_progress.txt",
    golden_reduced_file = "golden_reduced_Hello.sc",
    progress_dump_file = "reduction_progress.txt",
    reduction_algorithm = "perses_node_priority_with_dfs_delta",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

reduce(
    name = "reduce_scala_print_with_token_slicer",
    enable_edit_caching = True,
    enable_query_caching = False,  # Due to issue #65
    enable_token_slicer = True,
    progress_dump_file = "reduce_scala_print_with_token_slicer_reduction_progress.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    result_file = "Hello_reduced_with_token_slicer.sc",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_token_slicer",
    golden_file = "golden_reduced_hello_with_token_slicer.sc",
    test_file = "Hello_reduced_with_token_slicer.sc",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_token_slicer_progress",
    golden_file = "gold_test_reduce_scala_print_with_token_slicer_progress.txt",
    test_file = "reduce_scala_print_with_token_slicer_reduction_progress.txt",
)

reduce(
    name = "reduce_scala_print_with_tree_slicer",
    enable_edit_caching = True,
    enable_query_caching = False,  # Due to issue #65
    enable_tree_slicer = True,
    progress_dump_file = "reduce_scala_print_with_tree_slicer_reduction_progress.txt",
    reduction_algorithm = "perses_node_with_dfs_delta",
    result_file = "Hello_reduced_with_tree_slicer.sc",
    source_file = "Hello.sc",
    test_script = "r.sh",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_tree_slicer",
    golden_file = "golden_reduced_hello_with_tree_slicer.sc",
    test_file = "Hello_reduced_with_tree_slicer.sc",
)

golden_test(
    name = "gold_test_reduce_scala_print_with_tree_slicer_progress",
    golden_file = "gold_test_reduce_scala_print_with_tree_slicer_progress.txt",
    test_file = "reduce_scala_print_with_tree_slicer_reduction_progress.txt",
)