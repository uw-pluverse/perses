package(default_visibility = ["//test/org/perses:__subpackages__"])

load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")
load("//test/org/perses:test.bzl", "golden_test")

sanity_test(
    name = "sanity_test",
    source_files = ["hello.php"],
    test_script = "r.sh",
)

# Disable the test until we support PHP.
#reduction_golden_test(
#    name = "reduction_golden_test",
#    enable_edit_caching = True,
#    enable_query_caching = False,
#    golden_reduced_file = "golden.php",
#    reduction_algorithm = "perses_node_priority_with_dfs_delta",
#    source_file = "hello.php",
#    statistics_file = "statistics.txt",
#    test_script = "r.sh",
#)
