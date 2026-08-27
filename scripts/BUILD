load("@rules_python//python:defs.bzl", "py_library", "py_test")

package(default_visibility = ["//visibility:public"])

py_library(
    name = "release_scripts",
    srcs = [
        "bump_version.py",
        "generate_release_notes.py",
        "release.py",
    ],
    imports = ["."],
)

py_test(
    name = "make_jar_self_executable_test",
    srcs = ["make_jar_self_executable_test.py"],
    data = ["make_jar_self_executable.sh"],
)
