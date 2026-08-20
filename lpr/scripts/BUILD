load("@rules_python//python:defs.bzl", "py_library", "py_test")

package(default_visibility = [
    "//visibility:public",
])

exports_files([
    "llm_client.py",
    "llm_client_mock_to_test_functions.py",
    "llm_client_mock_to_test_workflow.py",
])

py_library(
    name = "llm_client",
    srcs = ["llm_client.py"],
)

py_test(
    name = "llm_client_test",
    srcs = ["llm_client_test.py"],
    deps = ["llm_client"],
)
