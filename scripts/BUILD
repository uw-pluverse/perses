load("@rules_python//python:defs.bzl", "py_library")

package(default_visibility = ["//visibility:public"])

exports_files(["make_jar_self_executable.sh"])

py_library(
    name = "release_scripts",
    srcs = [
        "bump_version.py",
        "generate_release_notes.py",
        "release.py",
    ],
    imports = ["."],
)
