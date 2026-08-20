load("//test:test.bzl", "sanity_test")

package(default_visibility = ["//test/org/perses:__subpackages__"])

sanity_test(
    name = "sanity_test",
    source_files = ["t.wat"],
    test_script = "r.sh",
)

# Disabled for its slow speed.
# reduction_golden_test(
#     name = "reduction_golden_test_for_literal_replacement",
#     enable_edit_caching = True,
#     enable_query_caching = True,
#     enable_token_reducer = False,
#     extra_output_files = [
#         "actionset_effect_profile.txt",
#     ],
#     # The following file is too large.
#     #     golden_progress_file = "golden_progress_for_literal_replacement.txt",
#     golden_reduced_file = "golden_reduced_for_literal_replacement_t.wat",
#     other_flags = {
#         "--fully-deterministic-mode": "true",
#         "--enable-literal-replacement-for-list-minimizer": "true",
#         "--enable-literal-replacement-for-regular-rule-node": "true",
#         "--fixpoint": "true",
#         "--actionset-effect-profile": "$(location actionset_effect_profile.txt)",
#     },
#     source_file = "t.wat",
#     test_script = "r.sh",
# )

# TODO(cnsun): need to have tests for actionset effect profiler.
# golden_test(
#     name = "golden_test_for_actionset_effect_profile",
#     golden_file = "golden_actionset_effect_profile.txt",
#     test_file = "actionset_effect_profile.txt",
# )

filegroup(
    name = "files",
    srcs = [
        "r.sh",
        "t.wat",
    ],
)
