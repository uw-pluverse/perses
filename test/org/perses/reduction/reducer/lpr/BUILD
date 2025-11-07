load("@io_bazel_rules_kotlin//kotlin:jvm.bzl", "kt_jvm_test")

package(default_visibility = [
    "//visibility:public",
])

kt_jvm_test(
    name = "LargeLanguageModelTest",
    srcs = [
        "LargeLanguageModelTest.kt",
    ],
    associates = [
        "//src/org/perses/reduction/reducer/lpr",
    ],
    data = [
        "//scripts/llm_scripts:llm_client_mock_to_test_functions.py",
    ],
    deps = [
        "//:truth",
    ],
)

kt_jvm_test(
    name = "AbstractLLMBasedReducerTest",
    srcs = [
        "AbstractLLMBasedReducerTest.kt",
    ],
    associates = [
        "//src/org/perses/reduction/reducer/lpr",
    ],
    data = [
        "test_data_type_elimination.c",
        "test_data_type_elimination.sh",
        "test_data_type_simplification.c",
        "test_data_type_simplification.sh",
        "test_function_inlining.c",
        "test_function_inlining.sh",
        "test_loop_unrolling.c",
        "test_loop_unrolling.sh",
        "test_variable_elimination.c",
        "test_variable_elimination.sh",
        "//scripts/llm_scripts:llm_client_mock_to_test_workflow.py",
    ],
    deps = [
        "//:truth",
        "//test/org/perses/reduction:reducer_functional_test_base",
    ],
)
