load("//test:test.bzl", "reduction_golden_test")

reduction_golden_test(
    name = "lpr_fixpoint_reduction_golden_test",
    golden_progress_file = "golden_reduction_with_lpr_fixpoint_progress.txt",
    golden_reduced_file = "golden_reduced_fixpoint_t.c",
    other_flags = {
        "--code-format": "COMPACT_ORIG_FORMAT",
        "--enable-lpr": "true",
        "--lpr-fixpoint": "true",
        "--llm-client-script": "$(location //lpr/scripts:llm_client_mock_to_test_workflow.py)",
    },
    progress_dump_file = "progress_dump_lpr_fixpoint.txt",
    source_file = "t.c",
    test_script = "r.sh",
    deps = ["//lpr/scripts:llm_client_mock_to_test_workflow.py"],
)

reduction_golden_test(
    name = "lpr_nofixpoint_reduction_golden_test",
    golden_progress_file = "golden_reduction_with_lpr_nofixpoint_progress.txt",
    golden_reduced_file = "golden_reduced_nofixpoint_t.c",
    other_flags = {
        "--code-format": "COMPACT_ORIG_FORMAT",
        "--enable-lpr": "true",
        "--lpr-fixpoint": "false",
        "--llm-client-script": "$(location //lpr/scripts:llm_client_mock_to_test_workflow.py)",
    },
    progress_dump_file = "progress_dump_lpr_nofixpoint.txt",
    source_file = "t.c",
    test_script = "r.sh",
    deps = ["//lpr/scripts:llm_client_mock_to_test_workflow.py"],
)
