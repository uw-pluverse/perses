load("@rules_python//python:defs.bzl", "py_test")

py_test(
    name = "make_jar_self_executable_test",
    srcs = ["make_jar_self_executable_test.py"],
    data = ["//scripts:make_jar_self_executable.sh"],
)

py_test(
    name = "release_scripts_test",
    srcs = ["release_scripts_test.py"],
    deps = ["//scripts:release_scripts"],
)
