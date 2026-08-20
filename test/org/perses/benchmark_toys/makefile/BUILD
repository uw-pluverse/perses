load("//test:test.bzl", "reduction_golden_test", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["Makefile"],
    test_script = "r.sh",
)

# The source is the extension-less name "Makefile", so this also exercises LanguageMakefile's
# file-name detection. ORIG_FORMAT is forced because make is whitespace-sensitive and it is the only
# format LanguageMakefile allows. enable_token_reducer runs trec on a Makefile -- the case that used
# to trip the token-count assertion (deleting the ')' of a `$(VAR)` splits one token into several);
# it is on here as a regression guard for trec's BEST_RESULT_SIZE_INCREASE classification.
reduction_golden_test(
    name = "reduction_golden_test",
    enable_edit_caching = True,
    enable_query_caching = True,
    enable_token_reducer = True,
    golden_progress_file = "golden_progress.txt",
    golden_reduced_file = "golden_reduced_Makefile",
    other_flags = {
        "--code-format": "ORIG_FORMAT",
    },
    reduction_algorithm = "node_priority",
    source_file = "Makefile",
    test_script = "r.sh",
)
