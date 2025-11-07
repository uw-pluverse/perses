load("//benchmark:benchmark.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["hello.php"],
    test_script = "r.sh",
)

reduction_golden_test(
    name = "reduction_golden_test",
    golden_progress_file = "golden_progress.txt",
    golden_reduced_file = "golden.php",
    source_file = "hello.php",
    test_script = "r.sh",
)
